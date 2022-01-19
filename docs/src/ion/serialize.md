# string ion\serialize(mixed $data, [?ion\Serializer $serializer = NULL])

Serialize a PHP value as ION data.

Serializes supported PHP values with the optionally provided \ion\Serializer:
* NULL
* bool
* int
* float
* string
* references
* arrays
* objects (incl. \Serializable, and classes implementing magic and custom __serialize)




## Params:

* mixed $data  
   PHP value(s).
* Optional ?ion\Serializer $serializer = NULL  
   Custom serializer.


## Returns:

* string, serialized ION data


