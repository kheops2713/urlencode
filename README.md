An idiot `urlencode` written in C using `libcurl`'s `quote_plus()` function.
Probably useless and already exists somewhere else with better code. But still,
I needed this.

Use: if called as `urlencode`, it will encode what is given as first argument
or standard input if none is given, and if it is called as `urldecode` it wil do
the same but decoding.

Limitations/bugs:

- an encoded URL containing `%00` will be truncated when decoded because it
  translates as a null character;
- it does not process strings longer than 4095 bytes;
- errors are not handled.
