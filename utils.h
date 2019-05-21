#ifndef UTILS_H_INCLUDED
#define UTILS_H_INCLUDED

void fatal(std::string message){
    std::cout << "[!!] Fatal error " << message << std::endl;
    getchar();
    exit(0);
}

template <typename T>
T clamp(T value, T min, T max){
    T n = value;
    if (n < min) n = min;
    if (n > max) n = max;

    return n;
}

#endif // UTILS_H_INCLUDED
