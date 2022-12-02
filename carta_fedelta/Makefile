OBJ= carta.o compito.o bst.o

Esame: $(OBJ)
	g++ -o Esame $(OBJ)

-include dependencies

.PHONY: depend clean cleanall

depend:
	g++ -MM *.cc > dependencies
clean:
	rm -f *.o
cleanall:
	rm -f Compito *.o *~
