project = NameOrganizer
source = NameOrganizer

$(project): $(source).o 
	g++ -o $(project) $(source).o 

$(source).o: $(source).cpp
	g++ -c $(source).cpp

tar: clean
	make $(project) > compile.txt
	./$(project) > output.txt
	rm *.o $(project)
	tar cvf $(project).tar.gz *


clean:
	rm *.o $(project)
