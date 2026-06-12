/* File: bounded_value.cpp
 * Author: Preston Seay
 *
 * This file implements the BoundedValue template class.
 * 
 * Somtimes, this implementation of the template would
 * be called a .tpp file, since it's somewhat special
 * as it's included at the bottom of the .h.
 */

// TODO: Constructor
template <typename T>
BoundedValue<T>::BoundedValue(T value, T minValue, T maxValue) {
    this->minValue = minValue;
    this->maxValue = maxValue;
    if (value >= minValue && value <= maxValue) {
        this->value = value;
    } else if (value < minValue) {
        this->value = minValue;
    } else {
        this->value = maxValue;
    }
}

// TODO: Return stored value
template <typename T>
T BoundedValue<T>::get() const {
    return value;
}

// TODO: Set value and enforce bounds
template <typename T>
void BoundedValue<T>::set(T newValue) {
    if (newValue >= minValue && newValue <= maxValue) {
        this->value = newValue;
    } else if (newValue < minValue) {
        this->value = minValue;
    } else {
        this->value = maxValue;
    }
}

// TODO: Return minimum bound
template <typename T>
T BoundedValue<T>::getMin() const {
    return minValue;
}

// TODO: Return maximum bound
template <typename T>
T BoundedValue<T>::getMax() const {
    return maxValue;
}

// BONUS: Add delta to value, keeping within bounds
template <typename T>
void BoundedValue<T>::adjust(T delta) {
    set(value + delta);
}