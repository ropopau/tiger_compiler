/**
 ** \file misc/singleton.hh
 ** \brief Generic singleton
 */

#pragma once

namespace misc
{

// Meyer pattern Singleton 
template <typename T>
class Singleton
{
public:
    // Delete implicite methods (Copy, Move, move assign, copy assign)
    Singleton(const Singleton&) = delete;
    Singleton(Singleton&&) = delete;
    Singleton operator=(Singleton&) = delete;
    Singleton operator=(const Singleton&) = delete;
    
    // Meyer pattern instance getter
    static const T& instance() {
        static T instance;
        return instance;
    }

protected:
    // Default constructor and destructor are protected because we dont want 
    // Singleton to be instantiated itself
    // Ctor
    Singleton() = default;
    // Dtor
    ~Singleton() = default;


private:
    Singleton instance = nullptr;
};

} // namespace misc
