# void ion\Reader\Options::__construct([?ion\Catalog $catalog = NULL, [?ion\Decimal\Context $decimalContext = NULL, [?Closure $onContextChange = NULL, [bool $returnSystemValues = false, [int $maxContainerDepth = 10, [int $maxAnnotations = 10, [int $annotationBufferSize = 16384, [int $tempBufferSize = 16384, [bool $skipCharacterValidation = false]]]]]]]]])








## Params:

* Optional ?ion\Catalog $catalog = NULL  
   ION catalog to use for symbol lookup.
* Optional ?ion\Decimal\Context $decimalContext = NULL  
   Decimal context to use.
* Optional ?Closure $onContextChange = NULL  
   Callback as function(\ion\Reader):void called upon local symbol table context change.
* Optional bool $returnSystemValues = false  
   Whether to return otherwise hidden system values.
* Optional int $maxContainerDepth = 10  
   The maximum depth of nested containers.
* Optional int $maxAnnotations = 10  
   The maximum number of annotations allowed on a single value.
* Optional int $annotationBufferSize = 16384  
   The maximum number of bytes of all annotations on a single value.
* Optional int $tempBufferSize = 16384  
   The maximum number of bytes of a symbol/value/chunk.
* Optional bool $skipCharacterValidation = false  
   Whether to skip UTF-8 validation.


