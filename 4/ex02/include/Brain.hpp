#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>

class Brain
{
	public:
		Brain( void );
		Brain( const Brain &src );
		virtual ~Brain( void );

		Brain &operator =( const Brain &rhs );

		void setIdea( const std::string &idea, size_t index );
		std::string getIdea( size_t index ) const;

	private:
		std::string ideas_[100];

		void InitIdeas( void );
};

#endif //BRAIN_HPP
