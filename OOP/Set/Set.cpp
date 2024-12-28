#include "Set.h"

Set::Set() : BoolVector(CHAR_RANGE) {}

Set::Set(const char* chars) : BoolVector(CHAR_RANGE) {
    while (*chars) {
        if (*chars >= MIN_CHAR && *chars < MAX_CHAR) {
            this->setBit(*chars - MIN_CHAR, true);
        }
        chars++;
    }
}
Set::Set(const BoolVector& other)
    :BoolVector(other)
{}

Set::Set(const Set& other) : BoolVector(other) {}

Set::~Set() {}

bool Set::contains(char c) const {
    if (c >= MIN_CHAR && c <= MAX_CHAR) {
        return this->bitValue(c - MIN_CHAR);
    }
    return false;
}

char Set::min() const {
    for (int i = 0; i < CHAR_RANGE; ++i) {
        if (bitValue(i)) {
            return i;
        }
    }
    throw std::runtime_error("Множество пусто");
}

char Set::max() const {
    for (int i = CHAR_RANGE - 1; i >= 0; --i) {
        if (bitValue(i)) {
            return i;
        }
    }
    throw std::runtime_error("Множество пусто");
}

int Set::size() const {
    return weight();
}

Set& Set::operator=(const Set& other) {
    if (this != &other) {
        BoolVector::operator=(other);
    }
    return *this;
}

bool Set::operator==(const Set& other) const
{
    for (int i = 0; i < CHAR_RANGE; i++)
        if (bitValue(i) != other.bitValue(i))
            return false;
    return true;
}

bool Set::operator!=(const Set& other) const {
    return !(*this == other);
}

Set Set:: operator|(const Set& other) const {
    Set result(boolVector.length());
    result.boolVector = this->boolVector | other.boolVector;
    return result;
}

Set& Set:: operator|=(const Set& other) {
    this->boolVector |= other.boolVector;
    return *this;
}

Set Set:: operator&(const Set& other) const {
    Set setCopy(BoolVector::operator&(other));
    return setCopy;
}

Set& Set::operator&=(const Set& other) {
    for (int i = 0; i < CHAR_RANGE; ++i) {
        this->setBit(i, this->bitValue(i) && other.bitValue(i));
    }
    return *this;
}

Set Set::operator~() const {
    Set result(BoolVector::operator~());
    
    return result;
}

Set Set::operator/(const Set& other) const
{
    Set result(BoolVector::operator&(~other));
    return result;
}

Set& Set::operator/=(const Set& other)
{
    operator/(other).swap(*this);
    return *this;
}



std::ostream& operator<<(std::ostream& os, const Set& cs) {
    os << "{ ";
    for (int i = 0; i < Set::CHAR_RANGE; ++i) {
        if (cs.bitValue(i)) {
            os << static_cast<char>(i + Set::MIN_CHAR) << " ";
        }
    }
    os << "}";
    return os;
}

std::istream& operator>>(std::istream& is, Set& cs) {
    std::string input;
    is >> input;

    cs = Set();

    for (char c : input) {
        if (c >= Set::MIN_CHAR && c < Set::MAX_CHAR) {
            cs.setBit(c - Set::MIN_CHAR, true);
        }
    }

    return is;
}

void Set::m_add(const char ch)
{
    setBitValue(ch, true);
}

void Set::m_remove(const char ch)
{
    setBitValue(ch, false);
}