

TARGET_EXEC ?= sorting.out

BUILD_DIR ?= ./build
SRC_DIRS ?= ./src
INC_DIRS ?= ./include

SRCS := $(shell find $(SRC_DIRS) -name *.cpp -or -name *.c)
OBJS := $(SRCS:%=$(BUILD_DIR)/%.o)
DEPS := $(OBJS:.o=.d)

INCS := $(shell find $(SRC_DIRS) $(INC_DIRS) -type d)
INC_FLAGS := $(addprefix -I,$(INCS))

CPPFLAGS ?= $(INC_FLAGS) -MMD -MP -pedantic-errors -Wall -Wextra -Wshadow -Wdouble-promotion -Wformat=2 -Wundef -fno-common -Wconversion -std=c++2a
C_FLAGS ?= $(INC_FLAGS) -MMD -MP -pedantic-errors -Wall -Wextra -Wshadow -Wdouble-promotion -Wformat=2 -Wundef -fno-common -Wconversion 

$(BUILD_DIR)/$(TARGET_EXEC): $(OBJS)
	$(CC) $(OBJS) -o $@ $(LDFLAGS)

$(BUILD_DIR)/%.c.o: %.c
	$(MKDIR_P) $(dir $@)
	$(CC) $(C_FLAGS) $(CFLAGS) -c $< -o $@


$(BUILD_DIR)/%.cpp.o: %.cpp
	$(MKDIR_P) $(dir $@)
	$(CC) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

.PHONY: clean

clean:
	$(RM) -r $(BUILD_DIR)

-include $(DEPS)

MKDIR_P ?= mkdir -p
