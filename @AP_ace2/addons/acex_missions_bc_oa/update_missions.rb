# Mission preprocessor/generator by Sickboy
# TODO: Preprocess 100%, and generate native mission.sqm instead?

# Check for Robocopy
begin
	%x[robocopy]
rescue
	puts "ERROR: Robocopy not found!"
	gets
	Process.exit
end

require 'fileutils'
require 'yaml'

CONFIG = File.open("config.yml") {|f| YAML::load(f)}

File.open("CfgMissions.hpp", 'w') do |f|
	f.puts <<STR
	class CfgMissions
	{
		class MPMissions
		{
STR

	CONFIG[:variants].each_pair do |v_key, v_value|
		variant = "mpmissions/#{v_key}"
		FileUtils.mkdir_p variant
		load 'mission.rb'
		str = File.open("shared/mission.sqm") {|file| file.read}
		CONFIG[:variants][v_key].each_pair do |s_key, s_value|
			str.gsub!("__FACTION#{s_key.to_s.upcase}__", "\"#{s_value}\"")
		end
		File.open("shared/mission.sqm", 'w') {|file| file.write str}
		count = 0
		CONFIG[:islands].each do |island|
			mf = "#{CONFIG[:mission]}.#{island[:name]}"
			setup = "#{variant}/#{mf}/setup.hpp"
			# bc = File.join("#{variant}/#{mf}/bc")
			# FileUtils.mkdir_p(bc) unless File.directory?(bc)
			system "robocopy /E shared #{variant}\\#{mf}"
			File.open(setup) do |f|
				s = f.read
				s.gsub!(/#define STARTPOS.*/, "#define STARTPOS #{island[:startpos]}")
				s.gsub!(/#define ADDONS.*/, "#define ADDONS #{island[:addons].map {|addon| "\"#{addon}\""}.join(",")}")
				File.open(setup, 'w') { |f| f.puts s }
			end
			f.puts <<STR
			class SIX_BattleCenter_#{v_key}#{count}
			{
				directory = "x\\acex\\addons\\missions_bc_oa\\mpmissions\\#{v_key}\\#{CONFIG[:mission]}.#{island[:name]}";
				//hidden = 0;
			};
STR
			count += 1
		end
	end
	f.puts <<STR
		};
	};
STR
end

gets
