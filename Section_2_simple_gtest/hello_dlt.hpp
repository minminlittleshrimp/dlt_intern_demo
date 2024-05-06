#ifndef LOG_TO_DAEMON_HPP
#define LOG_TO_DAEMON_HPP

void init_logging();
int log_message(const char* message);
void deinit_logging();

#endif 
