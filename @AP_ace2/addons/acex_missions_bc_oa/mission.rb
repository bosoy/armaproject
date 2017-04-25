group_item, vehicle_item, unit_id, unit_item = 0, 0, 0, 0

groups = File.open('groups.hpp') { |file| file.read }

str = File.open('mission.sqm') { |file| file.read }
str.gsub!("__INCLUDE groups\.hpp", groups)
str2 = ""
str.each_line do |line|
	case line
	when /__GROUPITEM__/
		line.sub!("__GROUPITEM__", group_item.to_s)
		group_item += 1
		unless group_item == 1
			str2.sub!("__TOTALUNITS__", unit_item.to_s)
		end
		unit_item = 0
	when /__UNITITEM__/
		line.sub!("__UNITITEM__", unit_item.to_s)
		unit_item += 1
	when /__UNITID__/
		line.sub!("__UNITID__", unit_id.to_s)
		unit_id += 1
	when /__VEHICLEITEM__/
		line.sub!("__VEHICLEITEM__", vehicle_item.to_s)
		vehicle_item += 1
	when /__UNITTEXT__/
		line.sub!("__UNITTEXT__", "\"p#{unit_id.to_s}\"")
	end
	str2 << line
end

str2.sub!("__TOTALUNITS__", unit_item.to_s) # Just the last group
str2.sub!("__TOTALVEHICLES__", vehicle_item.to_s)
str2.sub!("__TOTALGROUPS__", group_item.to_s)

puts "Written: #{group_item} groups and #{unit_id} unit ids"
File.open('shared/mission.sqm', 'w') { |file| file.puts str2 }
