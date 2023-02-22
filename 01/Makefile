.PHONY: all

OUTPUTS := $(basename $(shell find . -type f -name '*.cpp'))
WARNINGS := -Wall -Wextra -Wcast-align -Wcast-qual -Wctor-dtor-privacy -Wdisabled-optimization -Wformat=2 -Winit-self -Wlogical-op -Wmissing-include-dirs -Wnoexcept -Woverloaded-virtual -Wredundant-decls -Wshadow -Wsign-promo -Wstrict-null-sentinel -Wstrict-overflow=5 -Wswitch-default -Wundef -Werror -Wno-unused -pedantic

all: $(OUTPUTS)

./%: ./%.cpp
	g++ $(WARNINGS) -o $@ $<

clean:
	rm $(OUTPUTS)