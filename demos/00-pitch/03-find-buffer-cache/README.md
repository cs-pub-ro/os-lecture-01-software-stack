Run:

```console
\time -v find /usr/share > /dev/null
```

Then run again:

```console
\time -v find /usr/share > /dev/null
```

And again:

```console
\time -v find /usr/share > /dev/null
```

The 2nd and 3rd time are much faster.
Because the information is cached (in the buffer cache) - so the 2nd and 3rd time it is ready from memory.
