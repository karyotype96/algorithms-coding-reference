#ifndef UTILS_H_INCLUDED
#define UTILS_H_INCLUDED

// Clamps a value so it never goes under a minimum,
// nor exceeds a maximum.
template <typename T>
T clamp(T value, T min, T max){
    T n = value;
    if (n < min) n = min;
    if (n > max) n = max;

    return n;
}

// Prints a vector's contents.
void printVector(std::string prefix, std::vector<int> vec){
    std::cout << prefix << ": ";
    for (int i = 0; i < vec.size(); i++){
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;
}

#endif // UTILS_H_INCLUDED
