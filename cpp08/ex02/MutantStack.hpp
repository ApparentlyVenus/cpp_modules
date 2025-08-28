/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odana <odana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 21:20:57 by odana             #+#    #+#             */
/*   Updated: 2025/08/28 21:28:50 by odana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANT_STACK_HPP
# define MUTANT_STACK_HPP

#include <stack>

template<typename T>
class MutantStack : public std::stack<T>
{
    public:

        typedef typename std::stack<T>::container_type::iterator it;
        typedef typename std::stack<T>::container_type::const_iterator const_it;
        
        it begin() { return (this->c.begin()); }
        it end() { return (this->c.end()); }

        const_it begin() const { return (this->c.begin()); }
        const_it end() const { return (this->c.end()); }
};

#endif