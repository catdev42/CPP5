#!/bin/bash

if [ -z "$1" ]; then
    echo "Usage: $0 <ClassName>"
    exit 1
fi

CLASS_NAME=$1
HEADER_GUARD_NAME=$(echo "${CLASS_NAME}" | tr '[:lower:]' '[:upper:]')_HPP

#######HPP######
if [ -f "${CLASS_NAME}.hpp" ]; then
    echo "${CLASS_NAME}.hpp already exists"
    exit 1
fi

cat > ${CLASS_NAME}.hpp << EOL
#ifndef ${HEADER_GUARD_NAME}
#define ${HEADER_GUARD_NAME}

#include <iostream>

class ${CLASS_NAME} {
private:
    
public:
    ${CLASS_NAME}();
    ${CLASS_NAME}(${CLASS_NAME} const &src);
    ${CLASS_NAME} &operator=(${CLASS_NAME} const &rhs);
    ~${CLASS_NAME}();
};

std::ostream &operator<<(std::ostream &o, ${CLASS_NAME} const &infile);

#endif
EOL

echo "Generated ${CLASS_NAME}.hpp with template code"

#######CPP######

if [ -f "${CLASS_NAME}.cpp" ]; then
    echo "${CLASS_NAME}.cpp already exists"
    exit 1
fi

cat > ${CLASS_NAME}.cpp << EOL
#include "${CLASS_NAME}.hpp"
#include <iostream>

${CLASS_NAME}::${CLASS_NAME}()
{
    std::cout << "${CLASS_NAME} default constructor" << std::endl;
    return;
}

${CLASS_NAME}::${CLASS_NAME}(${CLASS_NAME} const &src)
{
    std::cout << "${CLASS_NAME} copy constructor" << std::endl;
    /*TODO*/;
    return;
}

${CLASS_NAME} &${CLASS_NAME}::operator=(${CLASS_NAME} const &rhs)
{
    std::cout << "${CLASS_NAME} copy assignment operator" << std::endl;
    if (this != &rhs)
    {
      /*TODO*/;
    }
    return *this;
}

${CLASS_NAME}::~${CLASS_NAME}()
{
    std::cout << "${CLASS_NAME} destructor" << std::endl;
    return;
}

/********************************************/
/********************************************/
/****** MEMBER FUNCTIONS ******/

/********************************************/
/********************************************/
/****** STREAM ******/

std::ostream &operator<<(std::ostream &o, const ${CLASS_NAME} &infile)
{
    o << std::endl;
    return o;
}

/********************************************/
/********************************************/
/****** PRIVATE ******/
EOL

echo "Generated ${CLASS_NAME}.cpp with template code"
