#pragma once
class safe_long_long_t {
private:
    long long value;

public:
    safe_long_long_t(long long value) {
        this->value = value;
    };

    safe_long_long_t() {
        this->value = 0;
    };

    safe_long_long_t &operator=(const safe_long_long_t &value) {
        this->value = value.value;
        return *this;
    }

    safe_long_long_t &operator+=(const safe_long_long_t &value) {
        this->value += value.value;
        return *this;
    }

    safe_long_long_t &operator-=(const safe_long_long_t &value) {
        this->value -= value.value;
        return *this;
    }

    safe_long_long_t &operator*=(const safe_long_long_t &value) {
        this->value *= value.value;
        return *this;
    }

    safe_long_long_t &operator/=(const safe_long_long_t &value) {
        this->value /= value.value;
        return *this;
    }

    safe_long_long_t &operator%=(const safe_long_long_t &value) {
        this->value %= value.value;
        return *this;
    }

    friend std::istream &operator>>(std::istream &is, safe_long_long_t &value);

    friend std::ostream &operator<<(std::ostream &os, const safe_long_long_t &value);

    friend bool operator==(const safe_long_long_t &value1, const safe_long_long_t &value2);

    friend bool operator>(const safe_long_long_t &value1, const safe_long_long_t &value2);
};

safe_long_long_t operator+(safe_long_long_t value1, const safe_long_long_t &value2) {
    return value1 += value2;
}

safe_long_long_t operator-(safe_long_long_t value1, const safe_long_long_t &value2) {
    return value1 -= value2;
}

safe_long_long_t operator*(safe_long_long_t value1, const safe_long_long_t &value2) {
    return value1 *= value2;
}

safe_long_long_t operator/(safe_long_long_t value1, const safe_long_long_t &value2) {
    return value1 /= value2;
}

safe_long_long_t operator%(safe_long_long_t value1, const safe_long_long_t &value2) {
    return value1 %= value2;
}

bool operator==(const safe_long_long_t &value1, const safe_long_long_t &value2) {
    return value1.value == value2.value;
}

bool operator>(const safe_long_long_t &value1, const safe_long_long_t &value2) {
    return value1.value > value2.value;
}

bool operator<(const safe_long_long_t &value1, const safe_long_long_t &value2) {
    return !((value1 > value2) || (value1 == value2));
}

bool operator>=(const safe_long_long_t &value1, const safe_long_long_t &value2) {
    return ((value1 > value2) || (value1 == value2));
}

bool operator<=(const safe_long_long_t &value1, const safe_long_long_t &value2) {
    return !(value1 > value2);
}

bool operator!=(const safe_long_long_t &value1, const safe_long_long_t &value2) {
    return !(value1 == value2);
}


std::ostream &operator<<(std::ostream &os, const safe_long_long_t &value) {
    os << value.value;
    return os;
}

std::istream &operator>>(std::istream &is, safe_long_long_t &value) {
    is >> value.value;
    return is;
}
