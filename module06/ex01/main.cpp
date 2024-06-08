/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echavez- <echavez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 23:21:27 by echavez-          #+#    #+#             */
/*   Updated: 2024/06/09 00:14:41 by echavez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main() {
    // Create a Data object
    Data originalData;
    originalData.id = 42;
    originalData.name = "Test";
    originalData.value = 3.14f;

	// Print the contents of the original Data object
	std::cout << "---Original Data object---" << std::endl;
	std::cout << originalData << std::endl << std::endl;

    // Serialize the Data object
    uintptr_t raw = Serializer::serialize(&originalData);
    std::cout << "Serialized Data pointer: " << raw << std::endl;

    // Deserialize the raw value
    Data* deserializedData = Serializer::deserialize(raw);
    std::cout << "Deserialized Data pointer: " << deserializedData << std::endl;

    /* Ensure the deserialized pointer compares equal to the original pointer
	** &originalData: address of the originalData object
	** deserializedData: address of the deserializedData object
	*/
	std::cout << "Comparing the deserialized pointer to the original pointer..." << std::endl;
    if (deserializedData == &originalData) {
        std::cout << "Success! The deserialized pointer is equal to the original pointer." << std::endl;
    } else {
        std::cout << "Failure! The deserialized pointer is not equal to the original pointer." << std::endl;
    }

    // Print the contents of the deserialized Data object
	std::cout <<  std::endl << "---Deserialized Data object---" << std::endl;
    std::cout << *deserializedData << std::endl;

    return 0;
}
