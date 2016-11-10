# This Makefile is donated to the Public Domain

CXX = g++-5
CXXOPTS = -std=c++11

all: executable
rebuild: clean all

debug: CXXFLAGS += -g
debug: executable

executable: main.o part.o head.o arm.o locomotor.o battery.o torso.o model.o customer.o sa.o order.o shop.o controller.o
	$(CXX) $(CXXOPTS) -std=c++11 -o 'rrs' 'main.o' 'part.o' 'head.o' 'arm.o' 'locomotor.o' 'battery.o' 'torso.o' 'model.o' 'customer.o' 'sa.o' 'order.o' 'shop.o' 'controller.o' -Wl,-L/usr/local/lib -lfltk
test: test.o part.o head.o arm.o locomotor.o battery.o torso.o model.o customer.o sa.o order.o shop.o controller.o
	$(CXX) $(CXXOPTS) -std=c++11 -o 'test' 'test.o' 'part.o' 'head.o' 'arm.o' 'locomotor.o' 'battery.o' 'torso.o' 'model.o' 'customer.o' 'sa.o' 'order.o' 'shop.o' 'controller.o' -Wl,-L/usr/local/lib -lfltk
main.o: main.cpp part.h model.h customer.h sa.h order.h shop.h controller.h
	$(CXX) -c $(CXXOPTS) $(fltk-config --cxxflags) main.cpp
part.o: part.cpp
	$(CXX) -c $(CXXOPTS) $(fltk-config --cxxflags) part.cpp
head.o: head.cpp head.h part.h
	$(CXX) -c $(CXXOPTS) $(fltk-config --cxxflags) head.cpp
arm.o: arm.cpp arm.h part.h
	$(CXX) -c $(CXXOPTS) $(fltk-config --cxxflags) arm.cpp
locomotor.o: locomotor.cpp locomotor.h part.h
	$(CXX) -c $(CXXOPTS) $(fltk-config --cxxflags) locomotor.cpp
battery.o: battery.cpp battery.h part.h
	$(CXX) -c $(CXXOPTS) $(fltk-config --cxxflags) battery.cpp
torso.o: torso.cpp torso.h part.h
	$(CXX) -c $(CXXOPTS) $(fltk-config --cxxflags) torso.cpp
model.o: model.cpp part.h head.h arm.h torso.h locomotor.h battery.h
	$(CXX) -c $(CXXOPTS) $(fltk-config --cxxflags) model.cpp
customer.o: customer.cpp part.h head.h arm.h torso.h locomotor.h battery.h
	$(CXX) -c $(CXXOPTS) $(fltk-config --cxxflags) customer.cpp
sa.o: sa.cpp part.h head.h arm.h torso.h locomotor.h battery.h
	$(CXX) -c $(CXXOPTS) $(fltk-config --cxxflags) sa.cpp
order.o: order.cpp model.h customer.h sa.h
	$(CXX) -c $(CXXOPTS) $(fltk-config --cxxflags) order.cpp
shop.o: shop.cpp shop.h arm.h battery.h head.h locomotor.h torso.h model.h customer.h sa.h order.h
	$(CXX) -c $(CXXOPTS) $(fltk-config --cxxflags) shop.cpp
controller.o: controller.cpp controller.h shop.h arm.h battery.h head.h locomotor.h torso.h model.h customer.h sa.h order.h
	$(CXX) -c $(CXXOPTS) $(fltk-config --cxxflags) controller.cpp
test.o: test.cpp part.h head.h arm.h locomotor.h battery.h torso.h model.h customer.h sa.h order.h shop.h
	$(CXX) -c $(CXXOPTS) $(fltk-config --cxxflags) test.cpp
clean:
	-rm -f *.o test
div:
	# 'X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-'
	# '-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X'
	# 'X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-'
	# '-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X'
