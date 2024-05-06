GTEST_DIR=../googletest/googletest
USER_DIR=.
CPPFLAGS += -isystem $(GTEST_DIR)/include
CPPFLAGS += -I$(USER_DIR)/include
CXXFLAGS += -g -Wall -Wextra -pthread

TESTS = gtest_dlt
DLT = hello_dlt

GTEST_HEADERS = $(GTEST_DIR)/include/gtest/*.h \
                $(GTEST_DIR)/include/gtest/internal/*.h

DLT_HEADERS = $(USER_DIR)/include/dlt/*.h

all: $(TESTS)
clean:
	rm -f $(TESTS)

GTEST_SRCS_ = $(GTEST_DIR)/src/*.cc $(GTEST_DIR)/src/*.h $(GTEST_HEADERS)
DLT_SRCS_ = $(USER_DIR)/src/*.cpp $(DLT_HEADERS) 

gtest-all.o : $(GTEST_SRCS_)
	$(CXX) $(CPPFLAGS) -I$(GTEST_DIR) $(CXXFLAGS) -c \
	$(GTEST_DIR)/src/gtest-all.cc

gtest_main.o : $(GTEST_SRCS_)
	$(CXX) $(CPPFLAGS) -I$(GTEST_DIR) $(CXXFLAGS) -c \
	$(GTEST_DIR)/src/gtest_main.cc

gtest.a : gtest-all.o
	$(AR) $(ARFLAGS) $@ $^

gtest_main.a : gtest-all.o gtest_main.o
	$(AR) $(ARFLAGS) $@ $^

hello_dlt.o : $(DLT_SRCS_)
	$(CXX) $(CPPFLAGS) -I$(USER_DIR) $(CXXFLAGS) -c \
	$(USER_DIR)/src/hello_dlt.cpp

gtest_dlt.o : $(DLT_SRCS_) $(GTEST_HEADERS)
	$(CXX) $(CPPFLAGS) -I$(USER_DIR) $(CXXFLAGS) -c \
	$(USER_DIR)/src/gtest_dlt.cpp

gtest_dlt : hello_dlt.o gtest_dlt.o gtest_main.a
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $^ -o $@
	rm -f *.a *.o
