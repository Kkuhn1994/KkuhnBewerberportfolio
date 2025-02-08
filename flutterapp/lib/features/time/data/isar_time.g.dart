// GENERATED CODE - DO NOT MODIFY BY HAND

part of 'isar_time.g.dart';

// // **************************************************************************
// // IsarCollectionGenerator
// // **************************************************************************

// // coverage:ignore-file
// // ignore_for_file: duplicate_ignore, non_constant_identifier_names, constant_identifier_names, invalid_use_of_protected_member, unnecessary_cast, prefer_const_constructors, lines_longer_than_80_chars, require_trailing_commas, inference_failure_on_function_invocation, unnecessary_parenthesis, unnecessary_raw_strings, unnecessary_null_checks, join_return_with_assignment, prefer_final_locals, avoid_js_rounded_ints, avoid_positional_boolean_parameters, always_specify_types

// extension GetTimeIsarCollection on Isar {
//   IsarCollection<TimeIsar> get timeIsars => this.collection();
// }

// const TimeIsarSchema = CollectionSchema(
//   name: r'TimeIsar',
//   id: 859031430156867719,
//   properties: {
//     r'end': PropertySchema(
//       id: 0,
//       name: r'end',
//       type: IsarType.string,
//     ),
//     r'start': PropertySchema(
//       id: 1,
//       name: r'start',
//       type: IsarType.string,
//     ),
//     r'type': PropertySchema(
//       id: 2,
//       name: r'type',
//       type: IsarType.string,
//     )
//   },
//   estimateSize: _timeIsarEstimateSize,
//   serialize: _timeIsarSerialize,
//   deserialize: _timeIsarDeserialize,
//   deserializeProp: _timeIsarDeserializeProp,
//   idName: r'id',
//   indexes: {},
//   links: {},
//   embeddedSchemas: {},
//   getId: _timeIsarGetId,
//   getLinks: _timeIsarGetLinks,
//   attach: _timeIsarAttach,
//   version: '3.1.8',
// );

// int _timeIsarEstimateSize(
//   TimeIsar object,
//   List<int> offsets,
//   Map<Type, List<int>> allOffsets,
// ) {
//   var bytesCount = offsets.last;
//   bytesCount += 3 + object.end.length * 3;
//   bytesCount += 3 + object.start.length * 3;
//   bytesCount += 3 + object.type.length * 3;
//   return bytesCount;
// }

// void _timeIsarSerialize(
//   TimeIsar object,
//   IsarWriter writer,
//   List<int> offsets,
//   Map<Type, List<int>> allOffsets,
// ) {
//   writer.writeString(offsets[0], object.end);
//   writer.writeString(offsets[1], object.start);
//   writer.writeString(offsets[2], object.type);
// }

// TimeIsar _timeIsarDeserialize(
//   Id id,
//   IsarReader reader,
//   List<int> offsets,
//   Map<Type, List<int>> allOffsets,
// ) {
//   final object = TimeIsar(
//     end: reader.readString(offsets[0]),
//     id: id,
//     start: reader.readString(offsets[1]),
//     type: reader.readString(offsets[2]),
//   );
//   return object;
// }

// P _timeIsarDeserializeProp<P>(
//   IsarReader reader,
//   int propertyId,
//   int offset,
//   Map<Type, List<int>> allOffsets,
// ) {
//   switch (propertyId) {
//     case 0:
//       return (reader.readString(offset)) as P;
//     case 1:
//       return (reader.readString(offset)) as P;
//     case 2:
//       return (reader.readString(offset)) as P;
//     default:
//       throw IsarError('Unknown property with id $propertyId');
//   }
// }

// Id _timeIsarGetId(TimeIsar object) {
//   return object.id;
// }

// List<IsarLinkBase<dynamic>> _timeIsarGetLinks(TimeIsar object) {
//   return [];
// }

// void _timeIsarAttach(IsarCollection<dynamic> col, Id id, TimeIsar object) {
//   object.id = id;
// }

// extension TimeIsarQueryWhereSort on QueryBuilder<TimeIsar, TimeIsar, QWhere> {
//   QueryBuilder<TimeIsar, TimeIsar, QAfterWhere> anyId() {
//     return QueryBuilder.apply(this, (query) {
//       return query.addWhereClause(const IdWhereClause.any());
//     });
//   }
// }

// extension TimeIsarQueryWhere on QueryBuilder<TimeIsar, TimeIsar, QWhereClause> {
//   QueryBuilder<TimeIsar, TimeIsar, QAfterWhereClause> idEqualTo(Id id) {
//     return QueryBuilder.apply(this, (query) {
//       return query.addWhereClause(IdWhereClause.between(
//         lower: id,
//         upper: id,
//       ));
//     });
//   }

//   QueryBuilder<TimeIsar, TimeIsar, QAfterWhereClause> idNotEqualTo(Id id) {
//     return QueryBuilder.apply(this, (query) {
//       if (query.whereSort == Sort.asc) {
//         return query
//             .addWhereClause(
//               IdWhereClause.lessThan(upper: id, includeUpper: false),
//             )
//             .addWhereClause(
//               IdWhereClause.greaterThan(lower: id, includeLower: false),
//             );
//       } else {
//         return query
//             .addWhereClause(
//               IdWhereClause.greaterThan(lower: id, includeLower: false),
//             )
//             .addWhereClause(
//               IdWhereClause.lessThan(upper: id, includeUpper: false),
//             );
//       }
//     });
//   }

//   QueryBuilder<TimeIsar, TimeIsar, QAfterWhereClause> idGreaterThan(Id id,
//       {bool include = false}) {
//     return QueryBuilder.apply(this, (query) {
//       return query.addWhereClause(
//         IdWhereClause.greaterThan(lower: id, includeLower: include),
//       );
//     });
//   }

//   QueryBuilder<TimeIsar, TimeIsar, QAfterWhereClause> idLessThan(Id id,
//       {bool include = false}) {
//     return QueryBuilder.apply(this, (query) {
//       return query.addWhereClause(
//         IdWhereClause.lessThan(upper: id, includeUpper: include),
//       );
//     });
//   }

//   QueryBuilder<TimeIsar, TimeIsar, QAfterWhereClause> idBetween(
//     Id lowerId,
//     Id upperId, {
//     bool includeLower = true,
//     bool includeUpper = true,
//   }) {
//     return QueryBuilder.apply(this, (query) {
//       return query.addWhereClause(IdWhereClause.between(
//         lower: lowerId,
//         includeLower: includeLower,
//         upper: upperId,
//         includeUpper: includeUpper,
//       ));
//     });
//   }
// }

// extension TimeIsarQueryFilter
//     on QueryBuilder<TimeIsar, TimeIsar, QFilterCondition> {
//   QueryBuilder<TimeIsar, TimeIsar, QAfterFilterCondition> endEqualTo(
//     String value, {
//     bool caseSensitive = true,
//   }) {
//     return QueryBuilder.apply(this, (query) {
//       return query.addFilterCondition(FilterCondition.equalTo(
//         property: r'end',
//         value: value,
//         caseSensitive: caseSensitive,
//       ));
//     });
//   }

//   QueryBuilder<TimeIsar, TimeIsar, QAfterFilterCondition> endGreaterThan(
//     String value, {
//     bool include = false,
//     bool caseSensitive = true,
//   }) {
//     return QueryBuilder.apply(this, (query) {
//       return query.addFilterCondition(FilterCondition.greaterThan(
//         include: include,
//         property: r'end',
//         value: value,
//         caseSensitive: caseSensitive,
//       ));
//     });
//   }

//   QueryBuilder<TimeIsar, TimeIsar, QAfterFilterCondition> endLessThan(
//     String value, {
//     bool include = false,
//     bool caseSensitive = true,
//   }) {
//     return QueryBuilder.apply(this, (query) {
//       return query.addFilterCondition(FilterCondition.lessThan(
//         include: include,
//         property: r'end',
//         value: value,
//         caseSensitive: caseSensitive,
//       ));
//     });
//   }

//   QueryBuilder<TimeIsar, TimeIsar, QAfterFilterCondition> endBetween(
//     String lower,
//     String upper, {
//     bool includeLower = true,
//     bool includeUpper = true,
//     bool caseSensitive = true,
//   }) {
//     return QueryBuilder.apply(this, (query) {
//       return query.addFilterCondition(FilterCondition.between(
//         property: r'end',
//         lower: lower,
//         includeLower: includeLower,
//         upper: upper,
//         includeUpper: includeUpper,
//         caseSensitive: caseSensitive,
//       ));
//     });
//   }

//   QueryBuilder<TimeIsar, TimeIsar, QAfterFilterCondition> endStartsWith(
//     String value, {
//     bool caseSensitive = true,
//   }) {
//     return QueryBuilder.apply(this, (query) {
//       return query.addFilterCondition(FilterCondition.startsWith(
//         property: r'end',
//         value: value,
//         caseSensitive: caseSensitive,
//       ));
//     });
//   }

//   QueryBuilder<TimeIsar, TimeIsar, QAfterFilterCondition> endEndsWith(
//     String value, {
//     bool caseSensitive = true,
//   }) {
//     return QueryBuilder.apply(this, (query) {
//       return query.addFilterCondition(FilterCondition.endsWith(
//         property: r'end',
//         value: value,
//         caseSensitive: caseSensitive,
//       ));
//     });
//   }

//   QueryBuilder<TimeIsar, TimeIsar, QAfterFilterCondition> endContains(
//       String value,
//       {bool caseSensitive = true}) {
//     return QueryBuilder.apply(this, (query) {
//       return query.addFilterCondition(FilterCondition.contains(
//         property: r'end',
//         value: value,
//         caseSensitive: caseSensitive,
//       ));
//     });
//   }

//   QueryBuilder<TimeIsar, TimeIsar, QAfterFilterCondition> endMatches(
//       String pattern,
//       {bool caseSensitive = true}) {
//     return QueryBuilder.apply(this, (query) {
//       return query.addFilterCondition(FilterCondition.matches(
//         property: r'end',
//         wildcard: pattern,
//         caseSensitive: caseSensitive,
//       ));
//     });
//   }

//   QueryBuilder<TimeIsar, TimeIsar, QAfterFilterCondition> endIsEmpty() {
//     return QueryBuilder.apply(this, (query) {
//       return query.addFilterCondition(FilterCondition.equalTo(
//         property: r'end',
//         value: '',
//       ));
//     });
//   }

//   QueryBuilder<TimeIsar, TimeIsar, QAfterFilterCondition> endIsNotEmpty() {
//     return QueryBuilder.apply(this, (query) {
//       return query.addFilterCondition(FilterCondition.greaterThan(
//         property: r'end',
//         value: '',
//       ));
//     });
//   }

//   QueryBuilder<TimeIsar, TimeIsar, QAfterFilterCondition> idEqualTo(Id value) {
//     return QueryBuilder.apply(this, (query) {
//       return query.addFilterCondition(FilterCondition.equalTo(
//         property: r'id',
//         value: value,
//       ));
//     });
//   }

//   QueryBuilder<TimeIsar, TimeIsar, QAfterFilterCondition> idGreaterThan(
//     Id value, {
//     bool include = false,
//   }) {
//     return QueryBuilder.apply(this, (query) {
//       return query.addFilterCondition(FilterCondition.greaterThan(
//         include: include,
//         property: r'id',
//         value: value,
//       ));
//     });
//   }

//   QueryBuilder<TimeIsar, TimeIsar, QAfterFilterCondition> idLessThan(
//     Id value, {
//     bool include = false,
//   }) {
//     return QueryBuilder.apply(this, (query) {
//       return query.addFilterCondition(FilterCondition.lessThan(
//         include: include,
//         property: r'id',
//         value: value,
//       ));
//     });
//   }

//   QueryBuilder<TimeIsar, TimeIsar, QAfterFilterCondition> idBetween(
//     Id lower,
//     Id upper, {
//     bool includeLower = true,
//     bool includeUpper = true,
//   }) {
//     return QueryBuilder.apply(this, (query) {
//       return query.addFilterCondition(FilterCondition.between(
//         property: r'id',
//         lower: lower,
//         includeLower: includeLower,
//         upper: upper,
//         includeUpper: includeUpper,
//       ));
//     });
//   }

//   QueryBuilder<TimeIsar, TimeIsar, QAfterFilterCondition> startEqualTo(
//     String value, {
//     bool caseSensitive = true,
//   }) {
//     return QueryBuilder.apply(this, (query) {
//       return query.addFilterCondition(FilterCondition.equalTo(
//         property: r'start',
//         value: value,
//         caseSensitive: caseSensitive,
//       ));
//     });
//   }

//   QueryBuilder<TimeIsar, TimeIsar, QAfterFilterCondition> startGreaterThan(
//     String value, {
//     bool include = false,
//     bool caseSensitive = true,
//   }) {
//     return QueryBuilder.apply(this, (query) {
//       return query.addFilterCondition(FilterCondition.greaterThan(
//         include: include,
//         property: r'start',
//         value: value,
//         caseSensitive: caseSensitive,
//       ));
//     });
//   }

//   QueryBuilder<TimeIsar, TimeIsar, QAfterFilterCondition> startLessThan(
//     String value, {
//     bool include = false,
//     bool caseSensitive = true,
//   }) {
//     return QueryBuilder.apply(this, (query) {
//       return query.addFilterCondition(FilterCondition.lessThan(
//         include: include,
//         property: r'start',
//         value: value,
//         caseSensitive: caseSensitive,
//       ));
//     });
//   }

//   QueryBuilder<TimeIsar, TimeIsar, QAfterFilterCondition> startBetween(
//     String lower,
//     String upper, {
//     bool includeLower = true,
//     bool includeUpper = true,
//     bool caseSensitive = true,
//   }) {
//     return QueryBuilder.apply(this, (query) {
//       return query.addFilterCondition(FilterCondition.between(
//         property: r'start',
//         lower: lower,
//         includeLower: includeLower,
//         upper: upper,
//         includeUpper: includeUpper,
//         caseSensitive: caseSensitive,
//       ));
//     });
//   }

//   QueryBuilder<TimeIsar, TimeIsar, QAfterFilterCondition> startStartsWith(
//     String value, {
//     bool caseSensitive = true,
//   }) {
//     return QueryBuilder.apply(this, (query) {
//       return query.addFilterCondition(FilterCondition.startsWith(
//         property: r'start',
//         value: value,
//         caseSensitive: caseSensitive,
//       ));
//     });
//   }

//   QueryBuilder<TimeIsar, TimeIsar, QAfterFilterCondition> startEndsWith(
//     String value, {
//     bool caseSensitive = true,
//   }) {
//     return QueryBuilder.apply(this, (query) {
//       return query.addFilterCondition(FilterCondition.endsWith(
//         property: r'start',
//         value: value,
//         caseSensitive: caseSensitive,
//       ));
//     });
//   }

//   QueryBuilder<TimeIsar, TimeIsar, QAfterFilterCondition> startContains(
//       String value,
//       {bool caseSensitive = true}) {
//     return QueryBuilder.apply(this, (query) {
//       return query.addFilterCondition(FilterCondition.contains(
//         property: r'start',
//         value: value,
//         caseSensitive: caseSensitive,
//       ));
//     });
//   }

//   QueryBuilder<TimeIsar, TimeIsar, QAfterFilterCondition> startMatches(
//       String pattern,
//       {bool caseSensitive = true}) {
//     return QueryBuilder.apply(this, (query) {
//       return query.addFilterCondition(FilterCondition.matches(
//         property: r'start',
//         wildcard: pattern,
//         caseSensitive: caseSensitive,
//       ));
//     });
//   }

//   QueryBuilder<TimeIsar, TimeIsar, QAfterFilterCondition> startIsEmpty() {
//     return QueryBuilder.apply(this, (query) {
//       return query.addFilterCondition(FilterCondition.equalTo(
//         property: r'start',
//         value: '',
//       ));
//     });
//   }

//   QueryBuilder<TimeIsar, TimeIsar, QAfterFilterCondition> startIsNotEmpty() {
//     return QueryBuilder.apply(this, (query) {
//       return query.addFilterCondition(FilterCondition.greaterThan(
//         property: r'start',
//         value: '',
//       ));
//     });
//   }

//   QueryBuilder<TimeIsar, TimeIsar, QAfterFilterCondition> typeEqualTo(
//     String value, {
//     bool caseSensitive = true,
//   }) {
//     return QueryBuilder.apply(this, (query) {
//       return query.addFilterCondition(FilterCondition.equalTo(
//         property: r'type',
//         value: value,
//         caseSensitive: caseSensitive,
//       ));
//     });
//   }

//   QueryBuilder<TimeIsar, TimeIsar, QAfterFilterCondition> typeGreaterThan(
//     String value, {
//     bool include = false,
//     bool caseSensitive = true,
//   }) {
//     return QueryBuilder.apply(this, (query) {
//       return query.addFilterCondition(FilterCondition.greaterThan(
//         include: include,
//         property: r'type',
//         value: value,
//         caseSensitive: caseSensitive,
//       ));
//     });
//   }

//   QueryBuilder<TimeIsar, TimeIsar, QAfterFilterCondition> typeLessThan(
//     String value, {
//     bool include = false,
//     bool caseSensitive = true,
//   }) {
//     return QueryBuilder.apply(this, (query) {
//       return query.addFilterCondition(FilterCondition.lessThan(
//         include: include,
//         property: r'type',
//         value: value,
//         caseSensitive: caseSensitive,
//       ));
//     });
//   }

//   QueryBuilder<TimeIsar, TimeIsar, QAfterFilterCondition> typeBetween(
//     String lower,
//     String upper, {
//     bool includeLower = true,
//     bool includeUpper = true,
//     bool caseSensitive = true,
//   }) {
//     return QueryBuilder.apply(this, (query) {
//       return query.addFilterCondition(FilterCondition.between(
//         property: r'type',
//         lower: lower,
//         includeLower: includeLower,
//         upper: upper,
//         includeUpper: includeUpper,
//         caseSensitive: caseSensitive,
//       ));
//     });
//   }

//   QueryBuilder<TimeIsar, TimeIsar, QAfterFilterCondition> typeStartsWith(
//     String value, {
//     bool caseSensitive = true,
//   }) {
//     return QueryBuilder.apply(this, (query) {
//       return query.addFilterCondition(FilterCondition.startsWith(
//         property: r'type',
//         value: value,
//         caseSensitive: caseSensitive,
//       ));
//     });
//   }

//   QueryBuilder<TimeIsar, TimeIsar, QAfterFilterCondition> typeEndsWith(
//     String value, {
//     bool caseSensitive = true,
//   }) {
//     return QueryBuilder.apply(this, (query) {
//       return query.addFilterCondition(FilterCondition.endsWith(
//         property: r'type',
//         value: value,
//         caseSensitive: caseSensitive,
//       ));
//     });
//   }

//   QueryBuilder<TimeIsar, TimeIsar, QAfterFilterCondition> typeContains(
//       String value,
//       {bool caseSensitive = true}) {
//     return QueryBuilder.apply(this, (query) {
//       return query.addFilterCondition(FilterCondition.contains(
//         property: r'type',
//         value: value,
//         caseSensitive: caseSensitive,
//       ));
//     });
//   }

//   QueryBuilder<TimeIsar, TimeIsar, QAfterFilterCondition> typeMatches(
//       String pattern,
//       {bool caseSensitive = true}) {
//     return QueryBuilder.apply(this, (query) {
//       return query.addFilterCondition(FilterCondition.matches(
//         property: r'type',
//         wildcard: pattern,
//         caseSensitive: caseSensitive,
//       ));
//     });
//   }

//   QueryBuilder<TimeIsar, TimeIsar, QAfterFilterCondition> typeIsEmpty() {
//     return QueryBuilder.apply(this, (query) {
//       return query.addFilterCondition(FilterCondition.equalTo(
//         property: r'type',
//         value: '',
//       ));
//     });
//   }

//   QueryBuilder<TimeIsar, TimeIsar, QAfterFilterCondition> typeIsNotEmpty() {
//     return QueryBuilder.apply(this, (query) {
//       return query.addFilterCondition(FilterCondition.greaterThan(
//         property: r'type',
//         value: '',
//       ));
//     });
//   }
// }

// extension TimeIsarQueryObject
//     on QueryBuilder<TimeIsar, TimeIsar, QFilterCondition> {}

// extension TimeIsarQueryLinks
//     on QueryBuilder<TimeIsar, TimeIsar, QFilterCondition> {}

// extension TimeIsarQuerySortBy on QueryBuilder<TimeIsar, TimeIsar, QSortBy> {
//   QueryBuilder<TimeIsar, TimeIsar, QAfterSortBy> sortByEnd() {
//     return QueryBuilder.apply(this, (query) {
//       return query.addSortBy(r'end', Sort.asc);
//     });
//   }

//   QueryBuilder<TimeIsar, TimeIsar, QAfterSortBy> sortByEndDesc() {
//     return QueryBuilder.apply(this, (query) {
//       return query.addSortBy(r'end', Sort.desc);
//     });
//   }

//   QueryBuilder<TimeIsar, TimeIsar, QAfterSortBy> sortByStart() {
//     return QueryBuilder.apply(this, (query) {
//       return query.addSortBy(r'start', Sort.asc);
//     });
//   }

//   QueryBuilder<TimeIsar, TimeIsar, QAfterSortBy> sortByStartDesc() {
//     return QueryBuilder.apply(this, (query) {
//       return query.addSortBy(r'start', Sort.desc);
//     });
//   }

//   QueryBuilder<TimeIsar, TimeIsar, QAfterSortBy> sortByType() {
//     return QueryBuilder.apply(this, (query) {
//       return query.addSortBy(r'type', Sort.asc);
//     });
//   }

//   QueryBuilder<TimeIsar, TimeIsar, QAfterSortBy> sortByTypeDesc() {
//     return QueryBuilder.apply(this, (query) {
//       return query.addSortBy(r'type', Sort.desc);
//     });
//   }
// }

// extension TimeIsarQuerySortThenBy
//     on QueryBuilder<TimeIsar, TimeIsar, QSortThenBy> {
//   QueryBuilder<TimeIsar, TimeIsar, QAfterSortBy> thenByEnd() {
//     return QueryBuilder.apply(this, (query) {
//       return query.addSortBy(r'end', Sort.asc);
//     });
//   }

//   QueryBuilder<TimeIsar, TimeIsar, QAfterSortBy> thenByEndDesc() {
//     return QueryBuilder.apply(this, (query) {
//       return query.addSortBy(r'end', Sort.desc);
//     });
//   }

//   QueryBuilder<TimeIsar, TimeIsar, QAfterSortBy> thenById() {
//     return QueryBuilder.apply(this, (query) {
//       return query.addSortBy(r'id', Sort.asc);
//     });
//   }

//   QueryBuilder<TimeIsar, TimeIsar, QAfterSortBy> thenByIdDesc() {
//     return QueryBuilder.apply(this, (query) {
//       return query.addSortBy(r'id', Sort.desc);
//     });
//   }

//   QueryBuilder<TimeIsar, TimeIsar, QAfterSortBy> thenByStart() {
//     return QueryBuilder.apply(this, (query) {
//       return query.addSortBy(r'start', Sort.asc);
//     });
//   }

//   QueryBuilder<TimeIsar, TimeIsar, QAfterSortBy> thenByStartDesc() {
//     return QueryBuilder.apply(this, (query) {
//       return query.addSortBy(r'start', Sort.desc);
//     });
//   }

//   QueryBuilder<TimeIsar, TimeIsar, QAfterSortBy> thenByType() {
//     return QueryBuilder.apply(this, (query) {
//       return query.addSortBy(r'type', Sort.asc);
//     });
//   }

//   QueryBuilder<TimeIsar, TimeIsar, QAfterSortBy> thenByTypeDesc() {
//     return QueryBuilder.apply(this, (query) {
//       return query.addSortBy(r'type', Sort.desc);
//     });
//   }
// }

// extension TimeIsarQueryWhereDistinct
//     on QueryBuilder<TimeIsar, TimeIsar, QDistinct> {
//   QueryBuilder<TimeIsar, TimeIsar, QDistinct> distinctByEnd(
//       {bool caseSensitive = true}) {
//     return QueryBuilder.apply(this, (query) {
//       return query.addDistinctBy(r'end', caseSensitive: caseSensitive);
//     });
//   }

//   QueryBuilder<TimeIsar, TimeIsar, QDistinct> distinctByStart(
//       {bool caseSensitive = true}) {
//     return QueryBuilder.apply(this, (query) {
//       return query.addDistinctBy(r'start', caseSensitive: caseSensitive);
//     });
//   }

//   QueryBuilder<TimeIsar, TimeIsar, QDistinct> distinctByType(
//       {bool caseSensitive = true}) {
//     return QueryBuilder.apply(this, (query) {
//       return query.addDistinctBy(r'type', caseSensitive: caseSensitive);
//     });
//   }
// }

// extension TimeIsarQueryProperty
//     on QueryBuilder<TimeIsar, TimeIsar, QQueryProperty> {
//   QueryBuilder<TimeIsar, int, QQueryOperations> idProperty() {
//     return QueryBuilder.apply(this, (query) {
//       return query.addPropertyName(r'id');
//     });
//   }

//   QueryBuilder<TimeIsar, String, QQueryOperations> endProperty() {
//     return QueryBuilder.apply(this, (query) {
//       return query.addPropertyName(r'end');
//     });
//   }

//   QueryBuilder<TimeIsar, String, QQueryOperations> startProperty() {
//     return QueryBuilder.apply(this, (query) {
//       return query.addPropertyName(r'start');
//     });
//   }

//   QueryBuilder<TimeIsar, String, QQueryOperations> typeProperty() {
//     return QueryBuilder.apply(this, (query) {
//       return query.addPropertyName(r'type');
//     });
//   }
// }
