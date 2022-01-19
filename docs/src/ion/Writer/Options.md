#  class ion\Writer\Options

ION writer options.






## Constants:

None.

## Properties:

 * public ?ion\Catalog $catalog  
  ION catalog to use for symbol lookup.
 * public ?ion\Decimal\Context $decimalContext  
  Decimal context to use.
 * public bool $outputBinary  
  Whether to output binary ION.
 * public bool $compactFloats  
  Whether to write doubles which fit in 32 bits as floats.
 * public bool $escapeNonAscii  
  Whether to slash-escape all non ASCII bytes.
 * public bool $prettyPrint  
  Whether to produce pretty-printed output.
 * public bool $indentTabs  
  Whether to indent with tabs, when pretty-printing.
 * public int $indentSize  
  The number of spaces to use for indentation instead of tabs, when pretty-printing.
 * public bool $flushEveryValue  
  Whether to immediately flush every value written.
 * public int $maxContainerDepth  
  Maximum depth of nested containers.
 * public int $maxAnnotations  
  The maximum number of annotations allowed on a single value.
 * public int $tempBufferSize  
  Temporary buffer size.

