#!/usr/bin/ruby
# mehrzero@gmail.com :]
def heart (char="@",message = "pck3r",sysSleep=0.009,cast=4,write_line = 1)
  messagelen= ""
  # head
  if (message.length % 2)!=0;message += " "end
  for x in 0...cast #2
    for y in 0..(4*cast) #1
      table1 = Math.sqrt( ((x-cast)**2) + ((y-cast)**2) )
      table2 = Math.sqrt( ((x-cast)**2) + ((y-3*cast)**2) )
      if (table1 < cast + 0.5 or table2 < cast + 0.5 )
        print char; sleep(sysSleep);
      else;print " " ;end
    end #1
    print "\n"
  end #2
  # down
  for x in 1..(2*cast) #5
    for y in 0...x ; print " "; end
     for y in 0...(4*cast+1-2*x) #4
      sleep (sysSleep)
      if (x>= write_line - 1 && x <= write_line + 1) #3
        index = y - (4*cast - 2*x - message.length) / 2
        if (index< message.length) && (index>= 0) #2
          if x == write_line # 1
            print message[index] # text message
          else print char end # 1
        else print char end #2
      else print char end #3
    end #4
    print "\n"
  end #5
end
heart()# start pck3r-heart
