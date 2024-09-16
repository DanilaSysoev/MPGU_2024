#include <vector>
#include <cmath>

static float discriminant(float a, float b, float c)
{
    return b * b - 4 * a * c;
}

int roots_count(float a, float b, float c)
{
    auto discr = discriminant(a, b, c);
    if (discr < 0) return 0;
    if (discr == 0) return 1;
    return 2;
}

std::vector<float> roots(float a, float b, float c)
{
    auto discr = discriminant(a, b, c);

    if (discr < 0) return {};
    if (discr == 0) return { -b / (2 * a) };

    auto sqrt_discr = std::sqrt(discr);
    return { (-b + sqrt_discr) / (2 * a), (-b - sqrt_discr) / (2 * a) };
}

bool has_roots(float a, float b, float c)
{
    return discriminant(a, b, c) >= 0;
}
