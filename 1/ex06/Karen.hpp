#ifndef KAREN_HPP
# define KAREN_HPP
# include <string>

class Karen
{
	typedef void (Karen::*MemberFuncs)( void );

	public:
		Karen( void );
		void complain( std::string level );
		static std::string levels_[4];

	private:
		void debug( void );
		void info( void );
		void warning( void );
		void error( void );
		MemberFuncs member_funcs_[4];
};

#endif //KAREN_HPP
