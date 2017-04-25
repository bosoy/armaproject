#!/usr/bin/env ruby
# encoding: UTF-8

rpt, version = ARGV
outputFile = "arma2_#{version.tr('.', '_')}_allconfig.cpp"
log = File.open("arma2_#{version.tr('.', '_')}_allconfig.log", 'w')

lcount = 0
icount = 0
ccount = 1
started = false
opened = 0
first = true
notfound = false
run = true

File.open(rpt) do |file|
  File.open(outputFile, 'w') do |out|
    while (line = file.gets) && run
      if line =~ /^class bin\\config.bin$/
        started = true
      end
      
      if started
        if line =~ /^[ \t]*class.*/
          ccount += 1
        end

        if line =~ /^[ \t]*[a-zA-Z0-9_\[\]]+ = .*/
          icount += 1
        end
        
        if line =~ /.*{.*/
          if first
            first = false
          else
            opened += 1
          end
        end
        
        if line =~ /.*}.*/
          opened -= 1
        end

        case line
          when /^String (.*) not found$/
            if not notfound
            notfound = true
            log.puts "Strings not found:"
            end
            log.puts $1
          else
            if started
              lcount += 1
              out.puts line
            end
        end
        if (opened < 0)
           run = false
        end
      end
    end
    log.puts "Extracted #{ccount} classes"
    log.puts "Extracted #{icount} config items"
    log.puts "Extracted #{lcount} lines"
    puts "Extracted #{lcount} lines"
    out.close
    file.close
    log.close
    exit
  end
end