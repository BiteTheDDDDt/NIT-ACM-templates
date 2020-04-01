namespace FastIO  {
	inline int read() {
		char ch = getchar(); int r = 0, w = 1;
		while(!isdigit(ch)) {if(ch == '-') w = -1; ch = getchar();}
		while(isdigit(ch)) {r = r * 10 + ch - '0', ch = getchar();}
		return r * w;
	}
	void _write(int x) {
		if(x < 0) putchar('-'), x = -x;
		if(x > 9) _write(x / 10);
		putchar(x % 10 + '0');
	}
	inline void write(int x) {
		_write(x);
		puts("");
	}
}