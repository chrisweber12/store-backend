make : main.cpp Store.cpp Store.hpp Customer.cpp Customer.hpp Product.cpp Product.hpp
	g++ -std=c++11 -o store-backend.exe main.cpp Store.cpp Customer.cpp Product.cpp
run:
	./store-backend.exe
clean :
	$(info Removing executable and all object files in directory)
	rm -f store-backend.exe
	rm -f *.o
	rm -f ./a.out
