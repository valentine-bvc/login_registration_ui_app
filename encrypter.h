#pragma once

#include <string>
#include <vector>
#include <iostream>


 const std::string finder {"QWERTYUIOPASDFGHJKLZXCVBNMqwertyuiopasdfghjklzxcvbnm1234567890!@#$%^&*()_+[]{}/\"'-.,| "};


std::string encode(std::string target){
    std::string result {};
	for(const char &c: target){
        size_t n {finder.find(c)};
		 if (n != std::string::npos){
			if(n+target.size() >= finder.size()){
				n+=target.size();
				n -= finder.size();
			}
			else
			 n+=target.size();

		   result.push_back(finder.at(n));
		}

	}

		return result;
}


std::string decode(std::string target) {
    int n{};
    int target_size = static_cast<int>(target.size());
    int finder_size = static_cast<int>(finder.size());
   std::string result {};
    for(const char &c: target){
        for(int i {}; i < finder_size;i++)
         if (c == finder[i]){
            if((i-target_size) <= 0){
                 n = i;
                n-=target.size();
                n += finder.size();
            }
            else {
                n = i;
                n-=target.size();
            }
           result.push_back(finder.at(n));
        }

    }

        return result;

}




