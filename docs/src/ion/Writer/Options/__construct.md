# void ion\Writer\Options::__construct([?ion\Catalog $catalog = NULL, [?ion\Decimal\Context $decimalContext = NULL, [bool $outputBinary = false, [bool $compactFloats = false, [bool $escapeNonAscii = false, [bool $prettyPrint = false, [bool $indentTabs = true, [int $indentSize = 2, [bool $flushEveryValue = false, [int $maxContainerDepth = 10, [int $maxAnnotations = 10, [int $tempBufferSize = 16384]]]]]]]]]]]])

Create custom ION writer options.






## Params:

* Optional ?ion\Catalog $catalog = NULL  
   ION catalog to use for symbol lookup.
* Optional ?ion\Decimal\Context $decimalContext = NULL  
   Decimal context to use.
* Optional bool $outputBinary = false  
   Whether to output binary ION.
* Optional bool $compactFloats = false  
   Whether to write doubles which fit in 32 bits as floats.
* Optional bool $escapeNonAscii = false  
   Whether to slash-escape all non ASCII bytes.
* Optional bool $prettyPrint = false  
   Whether to produce pretty-printed output.
* Optional bool $indentTabs = true  
   Whether to indent with tabs, when pretty-printing.
* Optional int $indentSize = 2  
   The number of spaces to use for indentation instead of tabs, when pretty-printing.
* Optional bool $flushEveryValue = false  
   Whether to immediately flush every value written.
* Optional int $maxContainerDepth = 10  
   Maximum depth of nested containers.
* Optional int $maxAnnotations = 10  
   The maximum number of annotations allowed on a single value.
* Optional int $tempBufferSize = 16384  
   Temporary buffer size.


