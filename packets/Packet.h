#pragma once
#include "string"
#include "vector"
namespace Packet {
    namespace errors {
        inline constexpr auto missing_required_fields = "missing required fields";
        inline constexpr auto invalid_numeric_fields = "invalid numeric fields";
    }

    std::vector<std::string> Split(const std::string& s, char delimiter);
    std::string Join(const std::vector<std::string>& Parts, char Delimiter);

    class Packet {
        public:
            bool isValid = true;
            std::string error;
            void SetInvalid(const std::string& reason) {
                isValid = false;
                error = reason;
            }
    };
}
