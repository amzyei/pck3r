#!/usr/bin/ruby
# mehrzero@gmail.com :]
require './requirements/library'
require 'fileutils'
puts "do you remov '/root/.minecraft' directory".brown
sys_status("start_install2")
Dir.chdir("/root") do
  if Dir.exists?".minecraft/tlauncher_libraries"# rm /root/.minecraft"
    puts "#{FileUtils.rm_rf(".minecraft")}".green
    sys_status("not_error")
  else
    puts "'/root/.minecraft/tlauncher_libraries ' directory  not found".red
  end
end
