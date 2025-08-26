/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odana <odana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 14:42:30 by odana             #+#    #+#             */
/*   Updated: 2025/08/26 14:44:09 by odana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Data.hpp"
#include <iostream>

int main()
{
    Data originalData(42, "test", 6.7);
    Data* originalPtr = &originalData;
    
    std::cout << "Original pointer: " << originalPtr << std::endl;
    
    uintptr_t serialized = Serializer::serialize(originalPtr);
    std::cout << "Serialized value: " << serialized << std::endl;
    
    Data* deserializedPtr = Serializer::deserialize(serialized);
    std::cout << "Deserialized pointer: " << deserializedPtr << std::endl;
    
    if (originalPtr == deserializedPtr)
    {
        std::cout << "SUCCESS: Pointers match!" << std::endl;
        std::cout << "Data content: id=" << deserializedPtr->id 
                  << ", name=" << deserializedPtr->str 
                  << ", value=" << deserializedPtr->val
                  << std::endl;
    }  
    return (0);
}