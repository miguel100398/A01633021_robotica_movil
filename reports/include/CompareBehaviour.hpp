#ifndef COMPAREBEHAVIOUR_HPP
#define COMPAREBEHAVIOUR_HPP 

template <typename T> class CompareBehaviour{
    public:
        virtual bool compare(T key1, T key2) = 0;
};

#endif //COMPAREBEHAVIOUR_HPP