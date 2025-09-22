#pragma once

namespace FragmentLM
{

using TokenizerFunction = char *(*)(const char *);

struct ITokenizer
{
    virtual ~ITokenizer() noexcept = default;
};

} // namespace FragmentLM
