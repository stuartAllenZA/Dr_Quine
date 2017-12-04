TARGET1 = Colleen

TARGET2 = Grace

TARGET3 = Sully

T1SRC = Colleen.c

T2SRC = Grace.c

T3SRC = Sully.c

CFLAGS = clang -Wall -Werror -Wextra -o

all : T1 T2 T3

clean :
	rm -rf $(TARGET1) $(TARGET2) $(TARGET3)

re : clean all

T1 : $(TARGET1)

$(TARGET1) :
	$(CFLAGS) $(TARGET1) $(T1SRC)

T1Test :
	./$(TARGET1) > tmp_Colleen
	diff tmp_Colleen $(T1SRC)

T2 : $(TARGET2)

$(TARGET2) :
	$(CFLAGS) $(TARGET2) $(T2SRC)

T2Test :
	./Grace
	diff $(T2SRC) Grace_kid.c

T3 : $(TARGET3)

$(TARGET3) :
	$(CFLAGS) $(TARGET3) $(T3SRC)

T2Test :
	./$(TARGET2) > tmp_Sully
	diff tmp_Sully $(T2SRC)
