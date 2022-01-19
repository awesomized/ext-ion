#  class ion\Serializer\PHP implements ion\Serializer

Specialization of the serializer for PHP.






## Constants:

None.

## Properties:

 * public ?ion\Writer\Options $writerOptions  
  Writer options.
 * public bool $multiSequence  
  Whether to write the top level array as multiple ION sequences.
 * public bool $callMagicSerialize  
  Whether to call magic __serialize() methods on objects to serialize.
 * public ?string $callCustomSerialize  
  Whether and which custom serialize method to call on objects to serialize.

