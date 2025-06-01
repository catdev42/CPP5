#ifndef CLASSNAME_HPP
#define CLASSNAME_HPP

# include <iostream>

class CLASSNAME {
private:
	
public:
	CLASSNAME();
	CLASSNAME( CLASSNAME const & src);
	CLASSNAME &	operator=( CLASSNAME const & rhs);
	~CLASSNAME();
};

std::ostream &operator<<(std::ostream &o, CLASSNAME const &infile);

#endif
