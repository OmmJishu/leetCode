#ifdef OY_LOCAL
#include "IO/LeetcodeIO.h"
using namespace std;
#else
namespace std {
    template <typename _Tp = uint32_t>
    constexpr _Tp __bit_floor(_Tp x) {
        if constexpr (sizeof(_Tp) == 4)
            return _Tp(1) << (31 - __builtin_clz(x));
        else
            return _Tp(1) << (63 - __builtin_clzll(x));
    }
    template <typename _Tp = uint32_t>
    constexpr _Tp __bit_ceil(_Tp x) {
        if constexpr (sizeof(_Tp) == 4)
            return x - 1 ? _Tp(1) << (32 - __builtin_clz(x - 1)) : x;
        else
            return x - 1 ? _Tp(1) << (64 - __builtin_clzll(x - 1)) : x;
    }
}
#endif

template <typename _Tp, typename _Fp, typename _Compare = std::less<void>>
bool chmax(_Tp &a, const _Fp &b, _Compare __comp = _Compare()) { return __comp(a, b) ? a = b, true : false; }
template <typename _Tp, typename _Fp, typename _Compare = std::less<void>>
bool chmin(_Tp &a, const _Fp &b, _Compare __comp = _Compare()) { return __comp(b, a) ? a = b, true : false; }
#define FUNCNAME
namespace OY {
    template <typename _ModType, _ModType _P>
    struct Modular {
        static constexpr _ModType mod() { return _P; }
        static constexpr _ModType mod(uint64_t __a) { return __a % _P; }
        static constexpr _ModType plus(_ModType __a, _ModType __b) {
            if (__a += __b; __a >= _P) __a -= _P;
            return __a;
        }
        static constexpr _ModType minus(_ModType __a, _ModType __b) {
            if (__a += _P - __b; __a >= _P) __a -= _P;
            return __a;
        }
        static constexpr _ModType multiply(uint64_t __a, uint64_t __b) {
            if constexpr (std::is_same_v<_ModType, uint64_t>)
                return multiply_ld(__a, __b);
            else
                return multiply_64(__a, __b);
        }
        static constexpr _ModType multiply_64(uint64_t __a, uint64_t __b) {
            // assert(__a * __b < 1ull << 64);
            return mod(__a * __b);
        }
        static constexpr _ModType multiply_128(uint64_t __a, uint64_t __b) { return __uint128_t(__a) * __b % _P; }
        static constexpr _ModType multiply_ld(uint64_t __a, uint64_t __b) {
            // assert(m_P < 1ull << 63 && __a < m_P && __b < m_P);
            int64_t res = __a * __b - uint64_t(1.L / _P * __a * __b) * _P;
            if (res < 0)
                res += _P;
            else if (res >= _P)
                res -= _P;
            return res;
        }
        static constexpr _ModType pow(uint64_t __a, uint64_t __n) {
            if constexpr (std::is_same_v<_ModType, uint64_t>)
                return pow_ld(__a, __n);
            else
                return pow_64(__a, __n);
        }
        static constexpr _ModType pow_64(uint64_t __a, uint64_t __n) {
            // assert(m_P < 1ull << 32);
            _ModType res = 1, b = mod(__a);
            while (__n) {
                if (__n & 1) res = multiply_64(res, b);
                b = multiply_64(b, b);
                __n >>= 1;
            }
            return res;
        }
        static constexpr _ModType pow_128(uint64_t __a, uint64_t __n) {
            _ModType res = 1, b = mod(__a);
            while (__n) {
                if (__n & 1) res = multiply_128(res, b);
                b = multiply_128(b, b);
                __n >>= 1;
            }
            return res;
        }
        static constexpr _ModType pow_ld(uint64_t __a, uint64_t __n) {
            _ModType res = 1, b = mod(__a);
            while (__n) {
                if (__n & 1) res = multiply_ld(res, b);
                b = multiply_ld(b, b);
                __n >>= 1;
            }
            return res;
        }
        template <typename _Tp>
        static constexpr _Tp divide(_Tp __a) { return __a / _P; }
        template <typename _Tp>
        static constexpr std::pair<_Tp, _Tp> divmod(_Tp __a) {
            _Tp quo = __a / _P, rem = __a - quo * _P;
            return {quo, rem};
        }
    };
    template <uint32_t _P>
    using Modular32 = Modular<uint32_t, _P>;
    template <uint64_t _P>
    using Modular64 = Modular<uint64_t, _P>;
}
namespace OY {
    template <typename _ModType, _ModType _P, bool _IsPrime = false>
    struct StaticModInt {
        using mint = StaticModInt<_ModType, _P, _IsPrime>;
        _ModType m_val;
        static_assert(_P > 1 && _P < 1ull << 63);
        constexpr StaticModInt() : m_val(0) {}
        template <typename _Tp, std::enable_if_t<std::is_signed_v<_Tp>, bool> = true>
        constexpr StaticModInt(_Tp __val) : m_val(0) {
            int64_t x = int64_t(__val) % int64_t(mod());
            if (x < 0) x += mod();
            m_val = x;
        }
        template <typename _Tp, std::enable_if_t<std::is_unsigned_v<_Tp>, bool> = true>
        constexpr StaticModInt(_Tp __val) : m_val(__val % mod()) {}
        static constexpr mint raw(_ModType __val) {
            mint res;
            res.m_val = __val;
            return res;
        }
        static constexpr _ModType mod() { return _P; }
        constexpr _ModType val() const { return m_val; }
        constexpr mint pow(uint64_t __n) const { return Modular<_ModType, _P>::pow(m_val, __n); }
        constexpr mint inv() const {
            if constexpr (_IsPrime)
                return inv_Fermat();
            else
                return inv_exgcd();
        }
        constexpr mint inv_exgcd() const {
            _ModType x = mod(), y = m_val, m0 = 0, m1 = 1;
            while (y) {
                _ModType z = x / y;
                x -= y * z;
                m0 -= m1 * z;
                std::swap(x, y);
                std::swap(m0, m1);
            }
            if (m0 >= mod()) m0 += mod() / x;
            return raw(m0);
        }
        constexpr mint inv_Fermat() const { return pow(mod() - 2); }
        constexpr mint &operator++() {
            if (++m_val == mod()) m_val = 0;
            return *this;
        }
        constexpr mint &operator--() {
            if (m_val == 0) m_val = mod();
            m_val--;
            return *this;
        }
        constexpr mint operator++(int) {
            mint old(*this);
            ++*this;
            return old;
        }
        constexpr mint operator--(int) {
            mint old(*this);
            --*this;
            return old;
        }
        constexpr mint &operator+=(const mint &__other) {
            m_val = Modular<_ModType, _P>::plus(m_val, __other.m_val);
            return *this;
        }
        constexpr mint &operator-=(const mint &__other) {
            m_val = Modular<_ModType, _P>::minus(m_val, __other.m_val);
            return *this;
        }
        constexpr mint &operator*=(const mint &__other) {
            m_val = Modular<_ModType, _P>::multiply(m_val, __other.m_val);
            return *this;
        }
        constexpr mint &operator/=(const mint &__other) { return *this *= __other.inv(); }
        constexpr mint operator+() const { return *this; }
        constexpr mint operator-() const { return raw(m_val ? mod() - m_val : 0); }
        constexpr bool operator==(const mint &__other) const { return m_val == __other.m_val; }
        constexpr bool operator!=(const mint &__other) const { return m_val != __other.m_val; }
        constexpr bool operator<(const mint &__other) const { return m_val < __other.m_val; }
        constexpr bool operator>(const mint &__other) const { return m_val > __other.m_val; }
        constexpr bool operator<=(const mint &__other) const { return m_val <= __other.m_val; }
        constexpr bool operator>=(const mint &__other) const { return m_val <= __other.m_val; }
        template <typename _Tp>
        constexpr explicit operator _Tp() const { return _Tp(m_val); }
        constexpr friend mint operator+(const mint &a, const mint &b) { return mint(a) += b; }
        constexpr friend mint operator-(const mint &a, const mint &b) { return mint(a) -= b; }
        constexpr friend mint operator*(const mint &a, const mint &b) { return mint(a) *= b; }
        constexpr friend mint operator/(const mint &a, const mint &b) { return mint(a) /= b; }
        template <typename _Istream>
        friend _Istream &operator>>(_Istream &is, mint &self) { return is >> self.m_val; }
        template <typename _Ostream>
        friend _Ostream &operator<<(_Ostream &os, const mint &self) { return os << self.m_val; }
    };
    template <uint32_t _P, bool _IsPrime>
    using StaticModInt32 = StaticModInt<uint32_t, _P, _IsPrime>;
    template <uint64_t _P, bool _IsPrime>
    using StaticModInt64 = StaticModInt<uint64_t, _P, _IsPrime>;
}
using mint = OY::StaticModInt32<1000000007, true>;
class Solution {
public:
    int minAbsoluteDifference(vector<int> &nums, int x) {
        if(!x)return 0;
        int n = nums.size();
        set<int> S;
        int ans = 0x3f3f3f3f;
        for (int r = 0; r < n; r++) {
            auto it = S.lower_bound(nums[r]);
            if (it != S.end()) chmin(ans, *it - nums[r]);
            if (it != S.begin()) {
                --it;
                if (it != S.end()) chmin(ans, nums[r] - *it);
            }
            int l=r-x+1;
            if(l>=0)S.insert(nums[l]);
        }
        return ans;
    }
};