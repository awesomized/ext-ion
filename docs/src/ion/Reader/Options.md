#  class ion\Reader\Options

Reader options.






## Constants:

None.

## Properties:

 * public ?ion\Catalog $catalog  
  ION catalog to use for symbol lookup.
 * public ?ion\Decimal\Context $decimalContext  
  Decimal context to use.
 * public ?Closure $onContextChange  
  Callback as function(\ion\Reader):void called upon local symbol table context change.
 * public bool $returnSystemValues  
  Whether to return otherwise hidden system values.
 * public int $maxContainerDepth  
  The maximum depth of nested containers.
 * public int $maxAnnotations  
  The maximum number of annotations allowed on a single value.
 * public int $annotationBufferSize  
  The maximum number of bytes of all annotations on a single value.
 * public int $tempBufferSize  
  The maximum number of bytes of a symbol/value/chunk.
 * public bool $skipCharacterValidation  
  Whether to skip UTF-8 validation.

