#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include "hiredis.h"

int main(int argc, char** argv) {
    redisContext *c;
    redisReply *reply;
    std::string hostname = (argc > 1) ? argv[1] : "127.0.0.1";
    int port = (argc > 2) ? std::atoi(argv[2]) : 6379;
    timeval timeout = {1, 500000};
    c = redisConnectWithTimeout(hostname.c_str(), port, timeout);
    if (c == NULL || c->err) {
        if (c) {
        std::cout << "Connection error: " << c->errstr << std::endl;
        redisFree(c);
        } else {
        std::cout << "Connection error: can't allocate redis context" << std::endl;
        exit(1);
        }
    }

    // Ping
    reply = (redisReply*)redisCommand(c, "PING");
    std::cout <<"PING: " << reply->str << std::endl;
    freeReplyObject(reply);

    // Set a key
    reply = (redisReply*)redisCommand(c, "SET %s %s", "foo", "hello world!");
    std::cout << "SET: " << reply->str << std::endl;
    freeReplyObject(reply);

    redisFree(c);
    return 0; 
}
