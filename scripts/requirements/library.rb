#!/usr/bin/ruby

 # mehrzero@gmail.com :]
 # example : sys_status() "error" or "not_error" or "start_install" or ""
class String # color zone
  def red;            "\e[31m#{self}\e[0m" end
  def green;          "\e[32m#{self}\e[0m" end
  def brown;          "\e[33m#{self}\e[0m" end
  def blue;           "\e[34m#{self}\e[0m" end
  # //////////////////////////////////////////
  def bold;           "\e[1m#{self}\e[22m" end
  def italic;         "\e[3m#{self}\e[23m" end
  def underline;      "\e[4m#{self}\e[24m" end
  def blink;          "\e[5m#{self}\e[25m" end
end
# ##########################################
def sys_status(status="")# "error" or "not_error" or "start_install" or ""
  if status=="error"
    print "尸⼕长㇌尺 :".red.bold," ERROR !".red.bold,"\n"

  elsif status=="not_error"
    print "尸⼕长㇌尺 :".green.bold," OK !".green.bold,"\n"
  elsif status=="start_install"
    print "尸⼕长㇌尺 :".brown.bold,"\n\t    Press ENTER key to continue or (exit ctrl+c)...".blink.brown.bold
    gets.chomp
  elsif status=="start_install2"
    print "尸⼕长㇌尺 :".brown.bold,"\n\t    Press ENTER key to continue or (exit ctrl+c)...".brown.bold
    gets.chomp
  else
    print "尸⼕长㇌尺 :".brown.bold,"\n\t    System status unknown".blink.brown.bold,"\n"
  end
end
