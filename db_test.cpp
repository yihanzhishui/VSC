// db 测试单元

#include <iostream>
#include <string>

enum MetaCommandResult {
    META_COMMAND_SUCCESS,
    META_COMMAND_UNRECOGNIZED_COMMAND
};

enum PrepareResult { PREPARE_SUCCESS, PREPARE_UNRECOGNIZED_STATEMENT };

enum StatementType { STATEMENT_INSERT, STATEMENT_SELECT };

class Statement {
  public:
    StatementType type;
};

class DB {
  public:
    void start();
    // 打印提示
    void print_prompt();
    // 解析元命令
    bool parse_meta_command(std::string &str);
    // 执行元命令
    MetaCommandResult do_meta_command(std::string &str);
    PrepareResult prepare_statement(std::string &input_line,
                                    Statement &statement);
    // 解析状态
    bool parse_statement(std::string &input_line, Statement &statement);
    // 执行状态
    void execute_statement(Statement &statement);
};

void DB::print_prompt() { std::cout << "db > "; }

// 执行元命令
MetaCommandResult do_meta_command(std::string &command) {
    if (command == ".exit") {
        std::cout << "Bye!\n";
        exit(EXIT_SUCCESS);
    } else
        return META_COMMAND_UNRECOGNIZED_COMMAND;
}

//
PrepareResult DB::prepare_statement(std::string &input_line,
                                    Statement &statement) {
    if (!input_line.compare(0, 6, "insert")) {
        statement.type = STATEMENT_INSERT;
        return PREPARE_SUCCESS;
    } else if (!input_line.compare(0, 6, "select")) {
        statement.type = STATEMENT_SELECT;
        return PREPARE_SUCCESS;
    } else
        return PREPARE_UNRECOGNIZED_STATEMENT;
}

bool DB::parse_statement(std::string &input_line, Statement &statement) {
    switch (prepare_statement(input_line, statement)) {
    case PREPARE_SUCCESS:
        return 0;
    case PREPARE_UNRECOGNIZED_STATEMENT:
        std::cout << "Unrecognized keyword at start of '" << input_line
                  << "'.\n";
        return 1;
    }
    return 0;
}

void DB::execute_statement(Statement &statement) {
    switch (statement.type) {
    case STATEMENT_INSERT:
        std::cout << "Execting insert statement\n";
        break;
    case STATEMENT_SELECT:
        std::cout << "Executing select statement\n";
        break;
    }
}

void DB::start() {
    while (1) {
        print_prompt();

        std::string input_line;
        std::getline(std::cin, input_line);

        if (parse_meta_command(input_line))
            continue;

        Statement statement;

        if (parse_statement(input_line, statement))
            continue;

        execute_statement(statement);
    }
}

int main() {
    DB db;
    db.start();
    return 0;
}