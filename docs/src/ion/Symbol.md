#  class ion\Symbol implements Stringable





See also [ION spec's symbol definition](https://amzn.github.io/ion-docs/docs/spec.html#symbol), and [ION spec's symbol guide](https://amzn.github.io/ion-docs/guides/symbols-guide.html).


## Constants:

None.

## Properties:

 * public ?string $value  
  The symbol's text representation.
 * public int $sid  
  The symbols ID, referencing its location within a shared symbol table.
 * public ?ion\Symbol\ImportLocation $importLocation  
  The import location referencing a shared symbol table.

