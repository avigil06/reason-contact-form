let component = ReasonReact.statelessComponent("TextArea");

let labelClassList = [|
  "block",
  "text-grey-darker",
  "text-sm",
  "font-bold",
  "mb-2",
|];

let inputClassList = [|
  "shadow",
  "appearance-none",
  "border",
  "rounded",
  "w-full",
  "py-2",
  "px-3",
  "text-grey-darker",
  "leading-tight",
  "focus:outline-none",
  "focus:shadow-outlin",
|];

let make = 
  (
    ~label,
    ~value,
    ~onChange,
    ~invalid,
    _children
  ) =>
{
  ...component,

  render: _self => {
    <div className={invalid ? "rr-input rr-input__invalid" : "rr-input"}>
      <label className="rr-input__label">
        {ReasonReact.string(label)}
      </label>
      <textarea
        className="rr-input__field"
        value
        onChange />
    </div>;
  },
};