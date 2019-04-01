type option('a) = None | Some('a);

type field = {
  name: string,
  value: string,
}

type fieldResult = {
  name: string,
  error: option(string)
}

type rule('a) =
  | NotEmpty;

let validate = (rule, value) =>
  switch (rule) {
  | NotEmpty => String.length(value) > 0
  };

let getError = (rule, field) =>
  switch (rule) {
    | NotEmpty => Some(field ++ " is required")
    };

let validateForm = model =>
  {
    Array.map(record => {
        let isValid = validate(NotEmpty, record.value);
        let error = getError(NotEmpty, record.name);
        {
          name: record.name,
          error: isValid ? None : error
        }
      }, model);
  }