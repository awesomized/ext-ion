#  class ion\Unserializer\PHP implements ion\Unserializer

Specialization of the unserializer for PHP.






## Constants:

None.

## Properties:

 * public ?ion\Reader\Options $readerOptions  
  Reader options.
 * public bool $multiSequence  
  Whether to continue reading multiple ION sequences after the first one.
 * public bool $callMagicUnserialize  
  Whether to call magic __unserialize() methods on objects to unserialize.
 * public ?string $callCustomUnserialize  
  Whether and which custom unserialize method to call on objects to unserialize.

