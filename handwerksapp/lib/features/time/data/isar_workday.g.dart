// GENERATED CODE - DO NOT MODIFY BY HAND

part of 'isar_workday.dart';

// **************************************************************************
// IsarCollectionGenerator
// **************************************************************************

// coverage:ignore-file
// ignore_for_file: duplicate_ignore, non_constant_identifier_names, constant_identifier_names, invalid_use_of_protected_member, unnecessary_cast, prefer_const_constructors, lines_longer_than_80_chars, require_trailing_commas, inference_failure_on_function_invocation, unnecessary_parenthesis, unnecessary_raw_strings, unnecessary_null_checks, join_return_with_assignment, prefer_final_locals, avoid_js_rounded_ints, avoid_positional_boolean_parameters, always_specify_types

extension GetIsarWorkdayCollection on Isar {
  IsarCollection<IsarWorkday> get isarWorkdays => this.collection();
}

const IsarWorkdaySchema = CollectionSchema(
  name: r'IsarWorkday',
  id: -5547927061118517655,
  properties: {
    r'date': PropertySchema(
      id: 0,
      name: r'date',
      type: IsarType.string,
    ),
    r'workAndBreakTimes': PropertySchema(
      id: 1,
      name: r'workAndBreakTimes',
      type: IsarType.stringList,
    )
  },
  estimateSize: _isarWorkdayEstimateSize,
  serialize: _isarWorkdaySerialize,
  deserialize: _isarWorkdayDeserialize,
  deserializeProp: _isarWorkdayDeserializeProp,
  idName: r'id',
  indexes: {},
  links: {},
  embeddedSchemas: {},
  getId: _isarWorkdayGetId,
  getLinks: _isarWorkdayGetLinks,
  attach: _isarWorkdayAttach,
  version: '3.1.8',
);

int _isarWorkdayEstimateSize(
  IsarWorkday object,
  List<int> offsets,
  Map<Type, List<int>> allOffsets,
) {
  var bytesCount = offsets.last;
  bytesCount += 3 + object.date.length * 3;
  bytesCount += 3 + object.workAndBreakTimes.length * 3;
  {
    for (var i = 0; i < object.workAndBreakTimes.length; i++) {
      final value = object.workAndBreakTimes[i];
      bytesCount += value.length * 3;
    }
  }
  return bytesCount;
}

void _isarWorkdaySerialize(
  IsarWorkday object,
  IsarWriter writer,
  List<int> offsets,
  Map<Type, List<int>> allOffsets,
) {
  writer.writeString(offsets[0], object.date);
  writer.writeStringList(offsets[1], object.workAndBreakTimes);
}

IsarWorkday _isarWorkdayDeserialize(
  Id id,
  IsarReader reader,
  List<int> offsets,
  Map<Type, List<int>> allOffsets,
) {
  final object = IsarWorkday(
    date: reader.readString(offsets[0]),
    id: id,
    workAndBreakTimes: reader.readStringList(offsets[1]) ?? [],
  );
  return object;
}

P _isarWorkdayDeserializeProp<P>(
  IsarReader reader,
  int propertyId,
  int offset,
  Map<Type, List<int>> allOffsets,
) {
  switch (propertyId) {
    case 0:
      return (reader.readString(offset)) as P;
    case 1:
      return (reader.readStringList(offset) ?? []) as P;
    default:
      throw IsarError('Unknown property with id $propertyId');
  }
}

Id _isarWorkdayGetId(IsarWorkday object) {
  return object.id;
}

List<IsarLinkBase<dynamic>> _isarWorkdayGetLinks(IsarWorkday object) {
  return [];
}

void _isarWorkdayAttach(
    IsarCollection<dynamic> col, Id id, IsarWorkday object) {
  object.id = id;
}

extension IsarWorkdayQueryWhereSort
    on QueryBuilder<IsarWorkday, IsarWorkday, QWhere> {
  QueryBuilder<IsarWorkday, IsarWorkday, QAfterWhere> anyId() {
    return QueryBuilder.apply(this, (query) {
      return query.addWhereClause(const IdWhereClause.any());
    });
  }
}

extension IsarWorkdayQueryWhere
    on QueryBuilder<IsarWorkday, IsarWorkday, QWhereClause> {
  QueryBuilder<IsarWorkday, IsarWorkday, QAfterWhereClause> idEqualTo(Id id) {
    return QueryBuilder.apply(this, (query) {
      return query.addWhereClause(IdWhereClause.between(
        lower: id,
        upper: id,
      ));
    });
  }

  QueryBuilder<IsarWorkday, IsarWorkday, QAfterWhereClause> idNotEqualTo(
      Id id) {
    return QueryBuilder.apply(this, (query) {
      if (query.whereSort == Sort.asc) {
        return query
            .addWhereClause(
              IdWhereClause.lessThan(upper: id, includeUpper: false),
            )
            .addWhereClause(
              IdWhereClause.greaterThan(lower: id, includeLower: false),
            );
      } else {
        return query
            .addWhereClause(
              IdWhereClause.greaterThan(lower: id, includeLower: false),
            )
            .addWhereClause(
              IdWhereClause.lessThan(upper: id, includeUpper: false),
            );
      }
    });
  }

  QueryBuilder<IsarWorkday, IsarWorkday, QAfterWhereClause> idGreaterThan(Id id,
      {bool include = false}) {
    return QueryBuilder.apply(this, (query) {
      return query.addWhereClause(
        IdWhereClause.greaterThan(lower: id, includeLower: include),
      );
    });
  }

  QueryBuilder<IsarWorkday, IsarWorkday, QAfterWhereClause> idLessThan(Id id,
      {bool include = false}) {
    return QueryBuilder.apply(this, (query) {
      return query.addWhereClause(
        IdWhereClause.lessThan(upper: id, includeUpper: include),
      );
    });
  }

  QueryBuilder<IsarWorkday, IsarWorkday, QAfterWhereClause> idBetween(
    Id lowerId,
    Id upperId, {
    bool includeLower = true,
    bool includeUpper = true,
  }) {
    return QueryBuilder.apply(this, (query) {
      return query.addWhereClause(IdWhereClause.between(
        lower: lowerId,
        includeLower: includeLower,
        upper: upperId,
        includeUpper: includeUpper,
      ));
    });
  }
}

extension IsarWorkdayQueryFilter
    on QueryBuilder<IsarWorkday, IsarWorkday, QFilterCondition> {
  QueryBuilder<IsarWorkday, IsarWorkday, QAfterFilterCondition> dateEqualTo(
    String value, {
    bool caseSensitive = true,
  }) {
    return QueryBuilder.apply(this, (query) {
      return query.addFilterCondition(FilterCondition.equalTo(
        property: r'date',
        value: value,
        caseSensitive: caseSensitive,
      ));
    });
  }

  QueryBuilder<IsarWorkday, IsarWorkday, QAfterFilterCondition> dateGreaterThan(
    String value, {
    bool include = false,
    bool caseSensitive = true,
  }) {
    return QueryBuilder.apply(this, (query) {
      return query.addFilterCondition(FilterCondition.greaterThan(
        include: include,
        property: r'date',
        value: value,
        caseSensitive: caseSensitive,
      ));
    });
  }

  QueryBuilder<IsarWorkday, IsarWorkday, QAfterFilterCondition> dateLessThan(
    String value, {
    bool include = false,
    bool caseSensitive = true,
  }) {
    return QueryBuilder.apply(this, (query) {
      return query.addFilterCondition(FilterCondition.lessThan(
        include: include,
        property: r'date',
        value: value,
        caseSensitive: caseSensitive,
      ));
    });
  }

  QueryBuilder<IsarWorkday, IsarWorkday, QAfterFilterCondition> dateBetween(
    String lower,
    String upper, {
    bool includeLower = true,
    bool includeUpper = true,
    bool caseSensitive = true,
  }) {
    return QueryBuilder.apply(this, (query) {
      return query.addFilterCondition(FilterCondition.between(
        property: r'date',
        lower: lower,
        includeLower: includeLower,
        upper: upper,
        includeUpper: includeUpper,
        caseSensitive: caseSensitive,
      ));
    });
  }

  QueryBuilder<IsarWorkday, IsarWorkday, QAfterFilterCondition> dateStartsWith(
    String value, {
    bool caseSensitive = true,
  }) {
    return QueryBuilder.apply(this, (query) {
      return query.addFilterCondition(FilterCondition.startsWith(
        property: r'date',
        value: value,
        caseSensitive: caseSensitive,
      ));
    });
  }

  QueryBuilder<IsarWorkday, IsarWorkday, QAfterFilterCondition> dateEndsWith(
    String value, {
    bool caseSensitive = true,
  }) {
    return QueryBuilder.apply(this, (query) {
      return query.addFilterCondition(FilterCondition.endsWith(
        property: r'date',
        value: value,
        caseSensitive: caseSensitive,
      ));
    });
  }

  QueryBuilder<IsarWorkday, IsarWorkday, QAfterFilterCondition> dateContains(
      String value,
      {bool caseSensitive = true}) {
    return QueryBuilder.apply(this, (query) {
      return query.addFilterCondition(FilterCondition.contains(
        property: r'date',
        value: value,
        caseSensitive: caseSensitive,
      ));
    });
  }

  QueryBuilder<IsarWorkday, IsarWorkday, QAfterFilterCondition> dateMatches(
      String pattern,
      {bool caseSensitive = true}) {
    return QueryBuilder.apply(this, (query) {
      return query.addFilterCondition(FilterCondition.matches(
        property: r'date',
        wildcard: pattern,
        caseSensitive: caseSensitive,
      ));
    });
  }

  QueryBuilder<IsarWorkday, IsarWorkday, QAfterFilterCondition> dateIsEmpty() {
    return QueryBuilder.apply(this, (query) {
      return query.addFilterCondition(FilterCondition.equalTo(
        property: r'date',
        value: '',
      ));
    });
  }

  QueryBuilder<IsarWorkday, IsarWorkday, QAfterFilterCondition>
      dateIsNotEmpty() {
    return QueryBuilder.apply(this, (query) {
      return query.addFilterCondition(FilterCondition.greaterThan(
        property: r'date',
        value: '',
      ));
    });
  }

  QueryBuilder<IsarWorkday, IsarWorkday, QAfterFilterCondition> idEqualTo(
      Id value) {
    return QueryBuilder.apply(this, (query) {
      return query.addFilterCondition(FilterCondition.equalTo(
        property: r'id',
        value: value,
      ));
    });
  }

  QueryBuilder<IsarWorkday, IsarWorkday, QAfterFilterCondition> idGreaterThan(
    Id value, {
    bool include = false,
  }) {
    return QueryBuilder.apply(this, (query) {
      return query.addFilterCondition(FilterCondition.greaterThan(
        include: include,
        property: r'id',
        value: value,
      ));
    });
  }

  QueryBuilder<IsarWorkday, IsarWorkday, QAfterFilterCondition> idLessThan(
    Id value, {
    bool include = false,
  }) {
    return QueryBuilder.apply(this, (query) {
      return query.addFilterCondition(FilterCondition.lessThan(
        include: include,
        property: r'id',
        value: value,
      ));
    });
  }

  QueryBuilder<IsarWorkday, IsarWorkday, QAfterFilterCondition> idBetween(
    Id lower,
    Id upper, {
    bool includeLower = true,
    bool includeUpper = true,
  }) {
    return QueryBuilder.apply(this, (query) {
      return query.addFilterCondition(FilterCondition.between(
        property: r'id',
        lower: lower,
        includeLower: includeLower,
        upper: upper,
        includeUpper: includeUpper,
      ));
    });
  }

  QueryBuilder<IsarWorkday, IsarWorkday, QAfterFilterCondition>
      workAndBreakTimesElementEqualTo(
    String value, {
    bool caseSensitive = true,
  }) {
    return QueryBuilder.apply(this, (query) {
      return query.addFilterCondition(FilterCondition.equalTo(
        property: r'workAndBreakTimes',
        value: value,
        caseSensitive: caseSensitive,
      ));
    });
  }

  QueryBuilder<IsarWorkday, IsarWorkday, QAfterFilterCondition>
      workAndBreakTimesElementGreaterThan(
    String value, {
    bool include = false,
    bool caseSensitive = true,
  }) {
    return QueryBuilder.apply(this, (query) {
      return query.addFilterCondition(FilterCondition.greaterThan(
        include: include,
        property: r'workAndBreakTimes',
        value: value,
        caseSensitive: caseSensitive,
      ));
    });
  }

  QueryBuilder<IsarWorkday, IsarWorkday, QAfterFilterCondition>
      workAndBreakTimesElementLessThan(
    String value, {
    bool include = false,
    bool caseSensitive = true,
  }) {
    return QueryBuilder.apply(this, (query) {
      return query.addFilterCondition(FilterCondition.lessThan(
        include: include,
        property: r'workAndBreakTimes',
        value: value,
        caseSensitive: caseSensitive,
      ));
    });
  }

  QueryBuilder<IsarWorkday, IsarWorkday, QAfterFilterCondition>
      workAndBreakTimesElementBetween(
    String lower,
    String upper, {
    bool includeLower = true,
    bool includeUpper = true,
    bool caseSensitive = true,
  }) {
    return QueryBuilder.apply(this, (query) {
      return query.addFilterCondition(FilterCondition.between(
        property: r'workAndBreakTimes',
        lower: lower,
        includeLower: includeLower,
        upper: upper,
        includeUpper: includeUpper,
        caseSensitive: caseSensitive,
      ));
    });
  }

  QueryBuilder<IsarWorkday, IsarWorkday, QAfterFilterCondition>
      workAndBreakTimesElementStartsWith(
    String value, {
    bool caseSensitive = true,
  }) {
    return QueryBuilder.apply(this, (query) {
      return query.addFilterCondition(FilterCondition.startsWith(
        property: r'workAndBreakTimes',
        value: value,
        caseSensitive: caseSensitive,
      ));
    });
  }

  QueryBuilder<IsarWorkday, IsarWorkday, QAfterFilterCondition>
      workAndBreakTimesElementEndsWith(
    String value, {
    bool caseSensitive = true,
  }) {
    return QueryBuilder.apply(this, (query) {
      return query.addFilterCondition(FilterCondition.endsWith(
        property: r'workAndBreakTimes',
        value: value,
        caseSensitive: caseSensitive,
      ));
    });
  }

  QueryBuilder<IsarWorkday, IsarWorkday, QAfterFilterCondition>
      workAndBreakTimesElementContains(String value,
          {bool caseSensitive = true}) {
    return QueryBuilder.apply(this, (query) {
      return query.addFilterCondition(FilterCondition.contains(
        property: r'workAndBreakTimes',
        value: value,
        caseSensitive: caseSensitive,
      ));
    });
  }

  QueryBuilder<IsarWorkday, IsarWorkday, QAfterFilterCondition>
      workAndBreakTimesElementMatches(String pattern,
          {bool caseSensitive = true}) {
    return QueryBuilder.apply(this, (query) {
      return query.addFilterCondition(FilterCondition.matches(
        property: r'workAndBreakTimes',
        wildcard: pattern,
        caseSensitive: caseSensitive,
      ));
    });
  }

  QueryBuilder<IsarWorkday, IsarWorkday, QAfterFilterCondition>
      workAndBreakTimesElementIsEmpty() {
    return QueryBuilder.apply(this, (query) {
      return query.addFilterCondition(FilterCondition.equalTo(
        property: r'workAndBreakTimes',
        value: '',
      ));
    });
  }

  QueryBuilder<IsarWorkday, IsarWorkday, QAfterFilterCondition>
      workAndBreakTimesElementIsNotEmpty() {
    return QueryBuilder.apply(this, (query) {
      return query.addFilterCondition(FilterCondition.greaterThan(
        property: r'workAndBreakTimes',
        value: '',
      ));
    });
  }

  QueryBuilder<IsarWorkday, IsarWorkday, QAfterFilterCondition>
      workAndBreakTimesLengthEqualTo(int length) {
    return QueryBuilder.apply(this, (query) {
      return query.listLength(
        r'workAndBreakTimes',
        length,
        true,
        length,
        true,
      );
    });
  }

  QueryBuilder<IsarWorkday, IsarWorkday, QAfterFilterCondition>
      workAndBreakTimesIsEmpty() {
    return QueryBuilder.apply(this, (query) {
      return query.listLength(
        r'workAndBreakTimes',
        0,
        true,
        0,
        true,
      );
    });
  }

  QueryBuilder<IsarWorkday, IsarWorkday, QAfterFilterCondition>
      workAndBreakTimesIsNotEmpty() {
    return QueryBuilder.apply(this, (query) {
      return query.listLength(
        r'workAndBreakTimes',
        0,
        false,
        999999,
        true,
      );
    });
  }

  QueryBuilder<IsarWorkday, IsarWorkday, QAfterFilterCondition>
      workAndBreakTimesLengthLessThan(
    int length, {
    bool include = false,
  }) {
    return QueryBuilder.apply(this, (query) {
      return query.listLength(
        r'workAndBreakTimes',
        0,
        true,
        length,
        include,
      );
    });
  }

  QueryBuilder<IsarWorkday, IsarWorkday, QAfterFilterCondition>
      workAndBreakTimesLengthGreaterThan(
    int length, {
    bool include = false,
  }) {
    return QueryBuilder.apply(this, (query) {
      return query.listLength(
        r'workAndBreakTimes',
        length,
        include,
        999999,
        true,
      );
    });
  }

  QueryBuilder<IsarWorkday, IsarWorkday, QAfterFilterCondition>
      workAndBreakTimesLengthBetween(
    int lower,
    int upper, {
    bool includeLower = true,
    bool includeUpper = true,
  }) {
    return QueryBuilder.apply(this, (query) {
      return query.listLength(
        r'workAndBreakTimes',
        lower,
        includeLower,
        upper,
        includeUpper,
      );
    });
  }
}

extension IsarWorkdayQueryObject
    on QueryBuilder<IsarWorkday, IsarWorkday, QFilterCondition> {}

extension IsarWorkdayQueryLinks
    on QueryBuilder<IsarWorkday, IsarWorkday, QFilterCondition> {}

extension IsarWorkdayQuerySortBy
    on QueryBuilder<IsarWorkday, IsarWorkday, QSortBy> {
  QueryBuilder<IsarWorkday, IsarWorkday, QAfterSortBy> sortByDate() {
    return QueryBuilder.apply(this, (query) {
      return query.addSortBy(r'date', Sort.asc);
    });
  }

  QueryBuilder<IsarWorkday, IsarWorkday, QAfterSortBy> sortByDateDesc() {
    return QueryBuilder.apply(this, (query) {
      return query.addSortBy(r'date', Sort.desc);
    });
  }
}

extension IsarWorkdayQuerySortThenBy
    on QueryBuilder<IsarWorkday, IsarWorkday, QSortThenBy> {
  QueryBuilder<IsarWorkday, IsarWorkday, QAfterSortBy> thenByDate() {
    return QueryBuilder.apply(this, (query) {
      return query.addSortBy(r'date', Sort.asc);
    });
  }

  QueryBuilder<IsarWorkday, IsarWorkday, QAfterSortBy> thenByDateDesc() {
    return QueryBuilder.apply(this, (query) {
      return query.addSortBy(r'date', Sort.desc);
    });
  }

  QueryBuilder<IsarWorkday, IsarWorkday, QAfterSortBy> thenById() {
    return QueryBuilder.apply(this, (query) {
      return query.addSortBy(r'id', Sort.asc);
    });
  }

  QueryBuilder<IsarWorkday, IsarWorkday, QAfterSortBy> thenByIdDesc() {
    return QueryBuilder.apply(this, (query) {
      return query.addSortBy(r'id', Sort.desc);
    });
  }
}

extension IsarWorkdayQueryWhereDistinct
    on QueryBuilder<IsarWorkday, IsarWorkday, QDistinct> {
  QueryBuilder<IsarWorkday, IsarWorkday, QDistinct> distinctByDate(
      {bool caseSensitive = true}) {
    return QueryBuilder.apply(this, (query) {
      return query.addDistinctBy(r'date', caseSensitive: caseSensitive);
    });
  }

  QueryBuilder<IsarWorkday, IsarWorkday, QDistinct>
      distinctByWorkAndBreakTimes() {
    return QueryBuilder.apply(this, (query) {
      return query.addDistinctBy(r'workAndBreakTimes');
    });
  }
}

extension IsarWorkdayQueryProperty
    on QueryBuilder<IsarWorkday, IsarWorkday, QQueryProperty> {
  QueryBuilder<IsarWorkday, int, QQueryOperations> idProperty() {
    return QueryBuilder.apply(this, (query) {
      return query.addPropertyName(r'id');
    });
  }

  QueryBuilder<IsarWorkday, String, QQueryOperations> dateProperty() {
    return QueryBuilder.apply(this, (query) {
      return query.addPropertyName(r'date');
    });
  }

  QueryBuilder<IsarWorkday, List<String>, QQueryOperations>
      workAndBreakTimesProperty() {
    return QueryBuilder.apply(this, (query) {
      return query.addPropertyName(r'workAndBreakTimes');
    });
  }
}
