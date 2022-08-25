#ifndef EXECUTER_HPP
# define EXECUTER_HPP

# include <string>

class Executor {
public:
	Executor();

	void promptEnterCommand();
	void executeCommand(const std::string &command);

	bool getIsRunning() const;

private:
	bool isRunning;
}

#endif