PROG = demo
OBJS = demo.o
CCFLAGS = -c -g
LDFLAGS = -g -lsqlite3

%.o: %.c
	gcc $(CCFLAGS) -o $@ $<

$(PROG): $(OBJS)
	gcc $(LDFLAGS) -o $@ $^

clean:
	rm -rf $(PROG) $(OBJS)
