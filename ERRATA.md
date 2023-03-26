# Errata för 'C-programmering i Linux, macOS, BSD och Solaris' (tredje utgåvan)

## Sidan 187–188 (simple-ls-ver2.c)
På sidan 188 i `simple-ls-ver2.c` har jag glömt att stänga `d` innan jag
returnerar. Testar man programmet med Valgrind kommer det att rapportera en
minnesläcka. Raden med `return 0;` ska således bytas ut mot:

```
    closedir(d)
    return 0;
```

Tack till [Warren Crutcher](https://github.com/warrenlc) som upptäckte detta
och skickade in en [rättning](https://github.com/jackbenny/c-programmering-tredje-utgavan/pull/1).

Koden är rättad på Github, och den korrekta finns således i [/kapitel11/simple-ls-ver2.c](simple-ls-ver2.c).
