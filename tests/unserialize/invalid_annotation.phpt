--TEST--
ion\unserialize/invalid annotation
--EXTENSIONS--
ion
--FILE--
TEST
<?php
foreach (["r::r::1", "R::R::1", "p::p::1", "p::foo::p::1", "c::c::1", "c::1", "E::foo::E::1",
			"E::1", "S::1", "S::S::foo123", "O::O::O::1", "O::1", "C::C::C::1", "C::1"] as $s) {
	try { var_dump(ion\unserialize($s)); }
	catch (Throwable $e) { printf("caught %s: %s\n", get_class($e), $e->getMessage()); }
}
?>
DONE
--EXPECT--
TEST
caught RuntimeException: Invalid multiple back reference annotations
caught RuntimeException: Invalid multiple reference annotations
int(1)
caught RuntimeException: Invalid multiple object property annotations
caught RuntimeException: Invalid object type annotation: c::1
caught RuntimeException: IERR_INVALID_ARG: ion_reader_get_an_annotation(ser->reader, ++i, &class_name)
caught RuntimeException: Invalid multiple object type annotations: E::E
caught RuntimeException: IERR_INVALID_ARG: ion_reader_get_an_annotation(ser->reader, ++i, &class_name)
caught RuntimeException: IERR_INVALID_ARG: ion_reader_get_an_annotation(ser->reader, ++i, &class_name)
caught RuntimeException: Class S does not implement Serializable
caught RuntimeException: Invalid multiple object type annotations: O::O
caught RuntimeException: IERR_INVALID_ARG: ion_reader_get_an_annotation(ser->reader, ++i, &class_name)
caught RuntimeException: Invalid multiple object type annotations: C::C
caught RuntimeException: IERR_INVALID_ARG: ion_reader_get_an_annotation(ser->reader, ++i, &class_name)
DONE
