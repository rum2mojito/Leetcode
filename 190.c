uint32_t reverseBits(uint32_t n) {
    uint32_t ret = 0;
    for(int i=0; i<32; i++) {
        ret = ret << 1;
        ret = (n & 1) | ret;
        n = n >> 1;
    }
    return ret;
}
