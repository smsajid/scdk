link = -lncurses
obj  = window.o color.o border.o pad.o main.o

ide: $(obj)
	 g++ $(link) -o ide $(obj)
	 rm -f *.o

window.o: window.h
color.o: color.h
border.o: border.h dimension.h
pad.o: pad.h

.PHONY: clean
clean:
	 rm -f ide $(obj)
