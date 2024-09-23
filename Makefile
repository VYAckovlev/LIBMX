
CC = clang
CFLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic


SRC_DIR = src
OBJ_DIR = obj
INC_DIR = inc


SRC_FILES = $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC_FILES))


LIB_NAME = libmx.a


all: $(LIB_NAME)


$(LIB_NAME): $(OBJ_FILES)
	@ar rcs $@ $^


$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@


$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)


clean:
	@rm -rf $(OBJ_DIR)


uninstall: clean
	@rm -f $(LIB_NAME)


reinstall: uninstall all

.PHONY: all clean uninstall reinstall
